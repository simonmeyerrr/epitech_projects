package epicalendar

import "time"

type Event struct {
	Title       string    `json:"title"`
	Id          string    `json:"uid"`
	Description string    `json:"description"`
	Location    string    `json:"location"`
	Categories  string    `json:"categories"`
	Start       time.Time `json:"start"`
	End         time.Time `json:"end"`
}

func (e *Event) ToICalendar() string {
	var event string
	event += "BEGIN:VEVENT" + "\r\n"
	event += "SUMMARY:" + e.Title + "\r\n"
	if e.Description != "" {
		event += "DESCRIPTION:" + e.Description + "\r\n"
	}
	if e.Location != "" {
		event += "LOCATION:" + e.Location + "\r\n"
	}
	if e.Categories != "" {
		event += "CATEGORIES:" + e.Categories + "\r\n"
	}
	if e.Id != "" {
		event += "UID:" + e.Id + "\r\n"
	}
	event += "DTSTART:" + e.Start.Add(time.Hour * -2).Format("20060102T150405Z") + "\r\n"
	event += "DTEND:" + e.End.Add(time.Hour * -2).Format("20060102T150405Z") + "\r\n"
	event += "DTSTAMP:" + time.Now().Add(time.Hour * -2).Format("20060102T150405Z") + "\r\n"
	event += "END:VEVENT" + "\r\n"
	return event
}

func EventsToIcalendar(events []Event) string {
	var res string
	res += "BEGIN:VCALENDAR" + "\r\n"
	res += "VERSION:2.0" + "\r\n"
	res += "PRODID:-//simonmeyer.me//epical//EN" + "\r\n"
	for _, event := range events {
		res += event.ToICalendar()
	}
	res += "END:VCALENDAR" + "\r\n"
	return res
}