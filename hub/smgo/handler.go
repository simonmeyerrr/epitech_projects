package smgo

import (
	"errors"
	"log"
	"net/http"
)

type (
	Handler func(*Arguments) int

	Decorator func(Handler) Handler
	Decorators []Decorator
)

func (h Handler) Decorate(decorators Decorators) Handler {
	for i := len(decorators); i > 0; i-- {
		h = decorators[i-1](h)
	}
	return h
}

func DefaultInvalidRouteHandler(a *Arguments) int {
	return ResponseStatus(a, http.StatusNotFound, nil)
}

func DefaultInvalidMethodHandler(a *Arguments) int {
	return ResponseStatus(a, http.StatusMethodNotAllowed, nil)
}

func DecorateAllowOrigin(h Handler) Handler {
	return func(args *Arguments) (status int) {
		AddHeaders(args, Headers{"Access-Control-Allow-Origin": {"*"}})
		return h(args)
	}
}

func DecorateLog(h Handler) Handler {
	return func(args *Arguments) (status int) {
		log.Printf("Received request: %s %s\n", args.Request.Method, args.Request.URL.Path)
		status = h(args)
		log.Printf("Produced response: %d\n", status)
		return
	}
}

func DecoratePanicJson(h Handler) Handler {
	return func(args *Arguments) (status int) {
		defer func() {
			if rc := recover(); rc != nil {
				status = ResponseJson(args, http.StatusInternalServerError, errors.New("internal server error"), nil)
			}
		}()
		return h(args)
	}
}

func DecoratePanicText(h Handler) Handler {
	return func(args *Arguments) (status int) {
		defer func() {
			if rc := recover(); rc != nil {
				status = ResponseText(args, http.StatusInternalServerError, "internal server error", nil)
			}
		}()
		return h(args)
	}
}

func DecoratePanicStatus(h Handler) Handler {
	return func(args *Arguments) (status int) {
		defer func() {
			if rc := recover(); rc != nil {
				status = ResponseStatus(args, http.StatusInternalServerError, nil)
			}
		}()
		return h(args)
	}
}
