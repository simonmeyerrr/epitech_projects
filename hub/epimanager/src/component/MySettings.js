import React, { Component } from 'react';
import { Switch } from 'antd';
import { Select } from 'antd';
import '../App.css';
import './MySettings.css';
const Option = Select.Option;
const WeekDay = ["Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi"]
const MonthName = ["Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre"]

export default class MySettings extends Component {
	constructor(props) {
		super(props);
		this.changeAssistant = this.changeAssistant.bind(this);
		this.changeTheme = this.changeTheme.bind(this);
		this.changeNotif = this.changeNotif.bind(this);
		this.changeTimeNotif = this.changeTimeNotif.bind(this);
	}
	changeAssistant(e) {
		let tmp = this.props.settings;
		tmp.assistant = e;
		localStorage.setItem('epimanager_settings', JSON.stringify(tmp));
		update_calendar();
		this.props.updateData();
	}
	changeTheme(e) {
    let tmp = this.props.settings;
		tmp.theme_dark = e;
		localStorage.setItem('epimanager_settings', JSON.stringify(tmp));
    this.props.updateData();
	}
	changeNotif(e) {
    let tmp = this.props.settings;
		tmp.notif = e;
		localStorage.setItem('epimanager_settings', JSON.stringify(tmp));
    this.props.updateData();
	}
	changeTimeNotif(e) {
    let tmp = this.props.settings;
		tmp.time_notif = e;
		localStorage.setItem('epimanager_settings', JSON.stringify(tmp));
    this.props.updateData();
	}
	render() {
		return (
			<div className="MySettings" >
				<div className="assistant">
					Afficher les activités que j{"'"}encadre:<br/>
					<Switch checked={this.props.settings.assistant} onChange={this.changeAssistant}/>
				</div>
				<div className="theme" >
					Thème dark:<br/>
					<Switch checked={this.props.settings.theme_dark} onChange={this.changeTheme}/>
				</div>
				<div className="notif" >
					Notifications avant <br/> une activité:<br/>
					<Switch checked={this.props.settings.notif} onChange={this.changeNotif} />
				</div>
				<div className="time" >
					M{"'"}avertir <br/>
					<Select disabled={!this.props.settings.notif} defaultValue={this.props.settings.time_notif} style={{ width: 120 }} onChange={this.changeTimeNotif}>
						<Option value={0}> 1 minute </Option>
						<Option value={1}> 5 minutes </Option>
						<Option value={2}> 10 minutes </Option>
					</Select> <br /> avant une activité.
				</div>
			</div>
		);
	}
}

function update_calendar() {
	let today = new Date();
	let nextWeek = new Date(today.getTime() + 6 * 24 * 60 * 60 * 1000);
	let date = today.getFullYear() + '-' + (today.getMonth() + 1) + '-' + today.getDate();
	let nextDate = nextWeek.getFullYear() + '-' + (nextWeek.getMonth() + 1) + '-' + nextWeek.getDate();

	let req2 = new XMLHttpRequest();
	req2.open('GET', "https://intra.epitech.eu/planning/load?format=json&start=" + date + "&end=" + nextDate, true);
	req2.onload = function (e) {
		if (req2.readyState === 4) {
			if (req2.status === 200) {
				let my_planning = get_planning(JSON.parse(req2.responseText));
				localStorage.setItem('epimanager_planning', JSON.stringify(my_planning));
			} else {
				let my_info2 = JSON.parse(localStorage.getItem('epimanager_info'));
				my_info2.error = 1;
				localStorage.setItem('epimanager_info', JSON.stringify(my_info2));
				console.log("Erreur de connexion à l'intra. (planning)");
			}
		}
	};
	req2.send(null);

	function getInfoActivity(fullInfo)
	{
		let info = {
			name: fullInfo.acti_title,
			start: fullInfo.start.split(" ")[1].split(":")[0] + ':' + fullInfo.start.split(" ")[1].split(":")[1],
			end: fullInfo.end.split(" ")[1].split(":")[0] + ':' + fullInfo.end.split(" ")[1].split(":")[1],
			room: fullInfo.room.code.split("/")[fullInfo.room.code.split("/").length - 1],
			link: 'https://intra.epitech.eu/module/' + fullInfo.scolaryear + '/' + fullInfo.codemodule + '/' + fullInfo.codeinstance + '/' + fullInfo.codeacti
		};
		if (fullInfo.type_code === "rdv" && fullInfo.event_registered) {
			info.start = fullInfo.rdv_group_registered.split("|")[0].split(" ")[1].split(":")[0] + ':' + fullInfo.rdv_group_registered.split("|")[0].split(" ")[1].split(":")[1];
			info.end = fullInfo.rdv_group_registered.split("|")[1].split(" ")[1].split(":")[0] + ':' + fullInfo.rdv_group_registered.split("|")[1].split(" ")[1].split(":")[1];
		}
		return (info);
	}
	function is_activity_ok(activity, assistant)
	{
		if (activity.acti_title === "HOMER") {
			return true;
		} else if (activity.event_registered === "registered") {
			return true;
		} else if (assistant === true) {
			if (activity.rights && activity.status_manager) {
				return true;
			}
		}
		return false;
	}
	function getWeekDay()
	{
		let tab = ["", "", "", "", "", "", ""];
		let day = today.getDay();

		for (let i = 0 ; i < 7 ; i++) {
			let j = (i + day) % 7;
			tab[i] = WeekDay[j];
		}
		for (let i = 0 ; i < 7 ; i++) {
			let oui = new Date(today.getTime() + i * 24 * 60 * 60 * 1000);
			tab[i] = tab[i] + ' ' + oui.getDate() + ' ' + MonthName[oui.getMonth()] + ' ' + oui.getFullYear();
		}
		return (tab);
	}
	function get_planning(oldtab)
	{
		let actual_day = today.getDay();
		let assistant = JSON.parse(localStorage.getItem('epimanager_settings')).assistant;
		let calendar = {
			date: getWeekDay(),
			planning: [
				[],
				[],
				[],
				[],
				[],
				[],
				[]
			]
		};
		for(let i= 0; i < oldtab.length; i++) {
			if (is_activity_ok(oldtab[i], assistant)) {
				let day = new Date(oldtab[i].start);
				let non = (day.getDay() - actual_day) % 7;
				if (non < 0) { non = non + 7;}
				calendar.planning[non].splice(0, 0, getInfoActivity(oldtab[i]));
			}
		}
		for (let i = 0 ; i < 7 ; i++) {
			for (let j = 0 ; j < calendar.planning[i].length - 1; j++) {
				if (calendar.planning[i][j] > calendar.planning[i][j + 1]) {
					let tmp = calendar.planning[i][j];
					calendar.planning[i][j] = calendar.planning[i][j + 1];
					calendar.planning[i][j + 1] = tmp;
					j = -1;
				}
			}
		}
		return (calendar);
	}
}
