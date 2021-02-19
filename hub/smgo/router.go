package smgo

import (
	"context"
	"fmt"
	"log"
	"net/http"
)

type (
	Arguments struct {
		Request    *http.Request               `json:"request"`
		Writer     http.ResponseWriter         `json:"-"`
		Context    context.Context             `json:"context"`
		PathValues PathValues                  `json:"path_values"`
		Other      map[interface{}]interface{} `json:"other"`
	}

	Method struct {
		Handler    Handler     `json:"-"`
		Decorators []Decorator `json:"-"`
	}
	Methods map[string]Method

	Route struct {
		Path       string        `json:"path"`
		ParsedPath []PathElement `json:"parsed_path"`
		Decorators Decorators    `json:"-"`
		Methods    Methods       `json:"methods"`
	}
	Routes []Route

	Router struct {
		Routes        Routes     `json:"Routes"`
		InvalidRoute  Handler    `json:"-"`
		InvalidMethod Handler    `json:"-"`
		Decorators    Decorators `json:"-"`
	}
	Routers []Routers
)

var (
	DefaultRouter = CreateRouter(DefaultInvalidRouteHandler, DefaultInvalidMethodHandler)
)

func CreateRouter(invalidRouteHandler, invalidMethodHandler Handler) Router {
	return Router{
		Routes:        make(Routes, 0),
		InvalidRoute:  invalidRouteHandler,
		InvalidMethod: invalidMethodHandler,
		Decorators:    Decorators{DecorateLog, DecoratePanicStatus, DecorateAllowOrigin},
	}
}

func (r *Router) AddRoute(route Route) error {
	parsedPath1, ok := parsePath(route.Path)
	if !ok {
		return fmt.Errorf("%s is not a valid path", route.Path)
	}
	route.ParsedPath = parsedPath1
	for i := range r.Routes {
		same := true
		parsedPath2 := r.Routes[i].ParsedPath
		if len(parsedPath1) != len(parsedPath2) {
			continue
		}
		for j := range parsedPath2 {
			if !parsedPath1[j].IsPathValue && !parsedPath2[j].IsPathValue && parsedPath1[j].Value != parsedPath2[j].Value {
				same = false
				break
			}
		}
		if same {
			return fmt.Errorf("%s is already in the router", route.Path)
		}
	}
	r.Routes = append(r.Routes, route)
	return nil
}

func (r *Router) AddRouteFatal(route Route) {
	if err := r.AddRoute(route); err != nil {
		log.Fatalln(err.Error())
	}
}

func (r *Router) findRoute(path string, args *Arguments) (Route, bool) {
	for _, route := range r.Routes {
		if ok := routeMatch(path, route.ParsedPath, args); ok {
			return route, true
		}
	}
	return Route{}, false
}

func (r Router) ServeHTTP(w http.ResponseWriter, req *http.Request) {
	if req == nil {
		return
	}
	var args = Arguments{
		Request:    req,
		Writer:     w,
		Context:    req.Context(),
		PathValues: nil,
		Other:      make(map[interface{}]interface{}),
	}
	if route, ok := r.findRoute(req.URL.Path, &args); !ok {
		r.InvalidRoute.Decorate(r.Decorators)(&args)
	} else if method, ok := route.Methods[req.Method]; !ok {
		r.InvalidMethod.Decorate(route.Decorators).Decorate(r.Decorators)(&args)
	} else {
		method.Handler.Decorate(method.Decorators).Decorate(route.Decorators).Decorate(r.Decorators)(&args)
	}
}
