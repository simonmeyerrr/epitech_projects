package main

import (
	"flag"
	"log"
	"net/http"
	"time"

	"github.com/simonmeyerrr/epicalendar"
	"github.com/simonmeyerrr/smgo"
)

const helpText = "Bienvenue sur EpiCalendar,\n\n" +
	"Pour synchroniser vos agenda à votre service d'agenda il suffit d'y ajouter les liens suivants:\n" +
	"- http://epicalendar.omnirem.dev/planning/{auth} pour le planning Epitech\n" +
	"- http://epicalendar.omnirem.dev/projects/{auth} pour le planning de projets Epitech\n" +
	"- http://epicalendar.omnirem.dev/end-projects/{auth} pour le planning de rendus de projets Epitech\n\n" +
	"Remplacez {auth} par votre code d'autologin que vous pouvez trouver à https://intra.epitech.eu/admin/autolog dans le format \"auth-jkfsdkjfdsvinn\""

func help(a *smgo.Arguments) int {
	return smgo.ResponseText(a, http.StatusOK, helpText, nil)
}

func planning(a *smgo.Arguments) int {
	auth := a.PathValues["auth"]
	planning, err := epicalendar.GetEpitechPlanning(auth, time.Now().Add(time.Hour * 24 * 7 * -1), time.Now().Add(time.Hour * 24 * 30))
	if err != nil {
		return smgo.ResponseText(a, http.StatusBadRequest, err.Error(), nil)
	}
	events := epicalendar.EpitechEventToEvent(epicalendar.GetRegisteredEvents(planning))
	ical := epicalendar.EventsToIcalendar(events)
	return smgo.ResponseText(a, http.StatusOK, ical, smgo.Headers{"Content-Type": []string{"text/calendar"}})
}

func projects(a *smgo.Arguments) int {
	auth := a.PathValues["auth"]
	projects, err := epicalendar.GetEpitechProjects(auth, time.Now().Add(time.Hour * 24 * 7 * -1), time.Now().Add(time.Hour * 24 * 30))
	if err != nil {
		return smgo.ResponseText(a, http.StatusBadRequest, err.Error(), nil)
	}
	events := epicalendar.EpitechProjectToEvent(epicalendar.GetRegisteredProjects(projects))
	ical := epicalendar.EventsToIcalendar(events)
	return smgo.ResponseText(a, http.StatusOK, ical, smgo.Headers{"Content-Type": []string{"text/calendar"}})
}

func endprojects(a *smgo.Arguments) int {
	auth := a.PathValues["auth"]
	projects, err := epicalendar.GetEpitechProjects(auth, time.Now().Add(time.Hour * 24 * 7 * -1), time.Now().Add(time.Hour * 24 * 30))
	if err != nil {
		return smgo.ResponseText(a, http.StatusBadRequest, err.Error(), nil)
	}
	events := epicalendar.EpitechProjectToEvent(epicalendar.GetRegisteredProjects(projects))
	newEvents := make([]epicalendar.Event, len(events))
	for i, event := range events {
		newEvents[i] = event
		newEvents[i].Title = "[END] " + event.Title
		newEvents[i].Start = event.End
		newEvents[i].End = event.End.Add(time.Minute)
		newEvents[i].Id += "End"
	}
	ical := epicalendar.EventsToIcalendar(newEvents)
	return smgo.ResponseText(a, http.StatusOK, ical, smgo.Headers{"Content-Type": []string{"text/calendar"}})
}

func main() {
	var port string
	flag.StringVar(&port, "port", "8000", "Port")
	flag.Parse()

	router := smgo.DefaultRouter
	router.Decorators = smgo.Decorators{smgo.DecorateLog, smgo.DecoratePanicStatus}
	router.AddRouteFatal(smgo.Route{
		Path: "/",
		Methods: smgo.Methods{
			http.MethodGet: {
				Handler: help,
			},
		},
	})
	router.AddRouteFatal(smgo.Route{
		Path: "/planning/:auth",
		Methods: smgo.Methods{
			http.MethodGet: {
				Handler: planning,
			},
		},
	})
	router.AddRouteFatal(smgo.Route{
		Path: "/projects/:auth",
		Methods: smgo.Methods{
			http.MethodGet: {
				Handler: projects,
			},
		},
	})
	router.AddRouteFatal(smgo.Route{
		Path: "/end-projects/:auth",
		Methods: smgo.Methods{
			http.MethodGet: {
				Handler: endprojects,
			},
		},
	})

	log.Println("Server listening on :" + port)
	if err := http.ListenAndServe(":" + port, router) ; err != nil {
		log.Fatal(err.Error())
	}
}
