package epicalendar

import (
	"encoding/json"
	"io/ioutil"
	"net/http"
	"time"
)

type EpitechProject struct {
	TitleModule  string   `json:"title_module"`
	CodeModule   string   `json:"codemodule"`
	ScolarYear   string   `json:"scolaryear"`
	CodeInstance string   `json:"codeinstance"`
	CodeLocation string   `json:"code_location"`
	BeginEvent   string   `json:"begin_event"`
	EndEvent     string   `json:"end_event"`
	Seats        string   `json:"seats"`
	NumEvent     string   `json:"num_event"`
	TypeActi     string   `json:"type_acti"`
	TypeActiCode string   `json:"type_acti_code"`
	CodeActi     string   `json:"codeacti"`
	ActiTitle    string   `json:"acti_title"`
	Num          string   `json:"num"`
	BeginActi    string   `json:"begin_acti"`
	EndActi      string   `json:"end_acti"`
	Registered   int64    `json:"registered"`
	InfoCrenneau string   `json:"info_creneau"`
	Project      string   `json:"project"`
	Rights       []string `json:"rights"`
}

func (e *EpitechProject) getTitle() string {
	return e.ActiTitle
}

func (e *EpitechProject) getDescription() string {
	return e.TypeActi
}

func (e *EpitechProject) getLocation() string {
	return e.CodeLocation
}

func (e *EpitechProject) getCategories() string {
	return e.TypeActiCode
}

func (e *EpitechProject) getStart() time.Time {

	if t, err := time.Parse("2006-01-02 15:04:05", e.BeginActi); err == nil {
		return t
	}
	return time.Time{}
}

func (e *EpitechProject) getEnd() time.Time {

	if t, err := time.Parse("2006-01-02 15:04:05", e.EndActi); err == nil {
		return t
	}
	return time.Time{}
}

func EpitechProjectToEvent(epi []EpitechProject) []Event {
	var events []Event
	for _, event := range epi {
		newEvent := Event{
			Title:       event.getTitle(),
			Id:          event.ActiTitle,
			Description: event.getDescription(),
			Location:    event.getLocation(),
			Categories:  event.getCategories(),
			Start:       event.getStart(),
			End:         event.getEnd(),
		}
		events = append(events, newEvent)
	}
	return events
}

func GetRegisteredProjects(all []EpitechProject) []EpitechProject {
	events := make([]EpitechProject, 0)
	for _, event := range all {
		if event.Registered == 1 && event.TypeActiCode == "proj" {
			events = append(events, event)
		}
	}
	return events
}

func GetEpitechProjects(autologin string, start, end time.Time) ([]EpitechProject, error) {
	var events []EpitechProject
	url := "https://intra.epitech.eu/" + autologin + "/module/board/?format=json&start=" + start.Format("2006-01-02") + "&end=" + end.Format("2006-01-02")
	if res, err := http.Get(url); err != nil {
		return nil, err
	} else if body, err := ioutil.ReadAll(res.Body); err != nil {
		return nil, err
	} else if err = json.Unmarshal(body, &events); err != nil {
		return nil, err
	}
	return events, nil
}
