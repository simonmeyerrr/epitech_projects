package epicalendar

import (
	"encoding/json"
	"io/ioutil"
	"net/http"
	"strings"
	"time"
)

type EpitechEvent struct {
	ScolarYear       string `json:"scolaryear"`
	CodeModule       string `json:"codemodule"`
	CodeInstance     string `json:"codeinstance"`
	CodeActi         string `json:"codeacti"`
	CodeEvent        string `json:"codeevent"`
	Semester         int64  `json:"semester"`
	InstanceLocation string `json:"instance_location"`
	TitleModule      string `json:"titlemodule"`
	ProfInst         [] struct {
		Type    string `json:"type"`
		Login   string `json:"login"`
		Title   string `json:"title"`
		Picture string `json:"picture"`
	} `json:"prof_inst"`
	ActiTitle               string `json:"acti_title"`
	NumEvent                int64  `json:"num_event"`
	Start                   string `json:"start"`
	End                     string `json:"end"`
	TotalStudentsRegistered int64  `json:"total_students_registered"`
	Title                   string `json:"title"`
	TypeTitle               string `json:"type_title"`
	TypeCode                string `json:"type_code"`
	IsRdv                   string `json:"is_rdv"`
	NbHours                 string `json:"nb_hours"`
	AllowedPlanningStart    string `json:"allowed_planning_start"`
	AllowedPlanningEnd      string `json:"allowed_planning_end"`
	NbGroup                 int64  `json:"nb_group"`
	NbMaxStudentsProjet     string `json:"nb_max_students_projet"`
	Room                    struct {
		Code  string `json:"code"`
		Type  string `json:"type"`
		Seats int64  `json:"seats"`
	} `json:"room"`
	Dates              interface{} `json:"dates"`
	ModuleAvailable    bool        `json:"module_available"`
	ModuleRegistered   bool        `json:"module_registered"`
	Past               bool        `json:"past"`
	AllowRegister      bool        `json:"allow_register"`
	EventRegistered    interface{} `json:"event_registered"`
	Display            string      `json:"display"`
	Project            bool        `json:"project"`
	RdvGroupRegistered string      `json:"rdv_group_registered"`
	RdvIndivRegistered string      `json:"rdv_indiv_registered"`
	AllowToken         bool        `json:"allow_token"`
	RegisterStudent    bool        `json:"register_student"`
	RegisterProf       bool        `json:"register_prof"`
	RegisterMonth      bool        `json:"register_month"`
	InMoreThanOneMonth bool        `json:"in_more_than_one_month"`
	Rights             interface{} `json:"rights"`
	StatusManager      string      `json:"status_manager"`
}

func (e *EpitechEvent) getTitle() string {
	if e.ActiTitle != "" {
		return e.ActiTitle
	} else {
		return e.Title
	}
}

func (e *EpitechEvent) getDescription() string {
	return e.TypeTitle
}

func (e *EpitechEvent) getLocation() string {
	slices := strings.Split(e.Room.Code, "/")
	if len(slices) > 0 {
		return slices[len(slices)-1]
	} else {
		return ""
	}
}

func (e *EpitechEvent) getCategories() string {
	return e.TypeCode
}

func (e *EpitechEvent) getStart() time.Time {
	if e.RdvIndivRegistered != "" {
		slices := strings.Split(e.RdvIndivRegistered, "|")
		if t, err := time.Parse("2006-01-02 15:04:05", slices[0]); err == nil {
			return t
		}
	} else if e.RdvGroupRegistered != "" {
		slices := strings.Split(e.RdvGroupRegistered, "|")
		if t, err := time.Parse("2006-01-02 15:04:05", slices[0]); err == nil {
			return t
		}
	} else {
		if t, err := time.Parse("2006-01-02 15:04:05", e.Start); err == nil {
			return t
		}
	}
	return time.Time{}
}

func (e *EpitechEvent) getEnd() time.Time {
	if e.RdvIndivRegistered != "" {
		slices := strings.Split(e.RdvIndivRegistered, "|")
		if t, err := time.Parse("2006-01-02 15:04:05", slices[1]); err == nil {
			return t
		}
	} else if e.RdvGroupRegistered != "" {
		slices := strings.Split(e.RdvGroupRegistered, "|")
		if t, err := time.Parse("2006-01-02 15:04:05", slices[1]); err == nil {
			return t
		}
	} else {
		if t, err := time.Parse("2006-01-02 15:04:05", e.End); err == nil {
			return t
		}
	}
	return time.Time{}
}

func EpitechEventToEvent(epi []EpitechEvent) []Event {
	var events []Event
	for _, event := range epi {
		newEvent := Event{
			Title:       event.getTitle(),
			Id:          event.CodeEvent,
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

func GetRegisteredEvents(all []EpitechEvent) []EpitechEvent {
	events := make([]EpitechEvent, 0)
	for _, event := range all {
		if registerd, ok := event.EventRegistered.(string); ok && registerd == "registered" {
			events = append(events, event)
		} else if registerd, ok := event.EventRegistered.(string); ok && registerd == "present" {
			events = append(events, event)
		} else if registerd, ok := event.EventRegistered.(string); ok && registerd == "absent" {
			events = append(events, event)
		} else if event.StatusManager == "accept" {
			events = append(events, event)
		} else if event.StatusManager == "eat" {
			events = append(events, event)
		}
	}
	return events
}

func GetEpitechPlanning(autologin string, start, end time.Time) ([]EpitechEvent, error) {
	var events []EpitechEvent
	url := "https://intra.epitech.eu/" + autologin + "/planning/load?format=json&start=" + start.Format("2006-01-02") + "&end=" + end.Format("2006-01-02")
	if res, err := http.Get(url); err != nil {
		return nil, err
	} else if body, err := ioutil.ReadAll(res.Body); err != nil {
		return nil, err
	} else if err = json.Unmarshal(body, &events); err != nil {
		return nil, err
	}
	return events, nil
}
