package smgo

import (
	"regexp"
	"strings"
)

type (
	PathValues map[string]string

	PathElement struct {
		IsPathValue bool   `json:"is_path_value"`
		Value       string `json:"value"`
	}
)

var regex = regexp.MustCompile("(\\/[a-z0-9_\\-\\.@]+|\\/:[a-z0-9_\\-\\.@]+)+")

func clearPath(path string) string {
	if strings.HasPrefix(path, "/") {
		path = path[1:]
	}
	if strings.HasSuffix(path, "/") {
		path = path[0 : len(path)-1]
	}
	return path
}

func routeMatch(path string, parsedPath []PathElement, args *Arguments) bool {
	path = clearPath(path)
	if path == "" {
		return len(parsedPath) == 0
	}
	slices := strings.Split(path, "/")
	if len(slices) != len(parsedPath) {
		return false
	}
	for i := 0; i < len(parsedPath); i++ {
		if !parsedPath[i].IsPathValue && parsedPath[i].Value != slices[i] {
			args.PathValues = nil
			return false
		} else if parsedPath[i].IsPathValue {
			if args.PathValues == nil {
				args.PathValues = make(PathValues, 0)
			}
			args.PathValues[parsedPath[i].Value] = slices[i]
		}
	}
	return true
}

func parsePath(path string) ([]PathElement, bool) {
	if path == "/" || path == "" {
		return []PathElement{}, true
	}
	if strs := regex.FindAllString(path, -1); len(strs) != 1 || strs[0] != path {
		return nil, false
	}
	path = clearPath(path)
	slices := strings.Split(path, "/")
	elems := make([]PathElement, len(slices))
	for i, slice := range slices {
		if strings.HasPrefix(slice, ":") {
			elems[i] = PathElement{true, slice[1:]}
		} else {
			elems[i] = PathElement{false, slice}
		}
	}
	return elems, true
}
