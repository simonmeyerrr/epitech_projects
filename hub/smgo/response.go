package smgo

import (
	"encoding/json"
	"io"
	"log"
	"mime"
	"path/filepath"
	"strconv"
	"time"
)

type (
	Headers map[string][]string

	Error struct {
		Error string `json:"error"`
	}
)

func AddHeaders(a *Arguments, headers Headers) {
	for header, content := range headers {
		if _, ok := a.Writer.Header()[header]; !ok {
			a.Writer.Header()[header] = content
		} else {
			a.Writer.Header()[header] = append(a.Writer.Header()[header], content...)
		}
	}
}

func ResponseStatus(a *Arguments, status int, headers map[string][]string) int {
	AddHeaders(a, headers)
	a.Writer.WriteHeader(status)
	return status
}

func ResponseText(a *Arguments, status int, body string, headers map[string][]string) int {
	AddHeaders(a, headers)
	a.Writer.WriteHeader(status)
	if _, err := a.Writer.Write([]byte(body)); err != nil {
		log.Printf("Failed to write text in body: %s\n", err.Error())
	}
	return status
}

func ResponseJson(a *Arguments, status int, body interface{}, headers Headers) int {
	a.Writer.Header()["Content-Type"] = []string{"application/json; charset=utf-8"}
	AddHeaders(a, headers)
	a.Writer.WriteHeader(status)
	e := json.NewEncoder(a.Writer)
	e.SetIndent("", "\t")
	if err, ok := body.(error); ok {
		body = Error{err.Error()}
	}
	if err := e.Encode(body); err != nil {
		log.Printf("Failed to encode json response: %s\n", err.Error())
	}
	return status
}

func ResponseFile(a *Arguments, status int, name string, content io.ReadSeeker, size int64, lastModified time.Time, headers Headers) int {
	if !lastModified.IsZero() {
		a.Writer.Header().Set("Last-Modified", lastModified.UTC().Format("Mon, 02 Jan 2006 15:04:05 GMT"))
	}
	a.Writer.Header().Set("Content-Type", mime.TypeByExtension(filepath.Ext(name)))
	a.Writer.Header().Set("Accept-Ranges", "bytes")
	a.Writer.Header().Set("Content-Length", strconv.FormatInt(size, 10))
	AddHeaders(a, headers)
	a.Writer.WriteHeader(status)
	var sendContent io.Reader = content
	io.CopyN(a.Writer, sendContent, size)
	return status
}
