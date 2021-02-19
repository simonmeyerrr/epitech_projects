const WeekDay = ["Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi"]
const MonthName = ["Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre"]

console.log("Starting background updates.");
prepare_epimanager();
updateEpimanager();
setInterval(updateEpimanager, 60000);

function updateEpimanager() {
	update_info();
	update_planning();
}

function prepare_epimanager() {
	localStorage.setItem('epimanager_info', JSON.stringify({
		error: 0,
		photo: "128.png",
		name: "N/A",
		credit: "0",
		gpa: "0"
	}));
	localStorage.setItem('epimanager_settings', JSON.stringify({
		assistant: false,
		theme_dark: true,
		notif: true,
		time_notif: 1
	}));
	localStorage.setItem('epimanager_planning', JSON.stringify({
		date: ["", "", "", "", "", "", ""],
		planning: [
			[],
			[],
			[],
			[],
			[],
			[],
			[]
		]
	}));
}

function update_info() {
	let saved = JSON.parse(localStorage.getItem('epimanager_info'));
	let my_info = {
		error: saved.error,
		photo: saved.photo,
		name: saved.name,
		credit: saved.credit,
		gpa: saved.gpa
	};
	let req = new XMLHttpRequest();
	req.open('GET', 'https://intra.epitech.eu/user/?format=json', true);
	req.onload = function (e) {
		if (req.readyState === 4) {
			if (req.status === 200) {
				let rep = JSON.parse(req.responseText);
				my_info.photo = rep.picture;
				my_info.name = rep.title;
				my_info.credit = rep.credits;
				my_info.gpa = rep.gpa[0].gpa;
				my_info.error = 0;
				localStorage.setItem('epimanager_info', JSON.stringify(my_info));
			} else {
				my_info.error = 1;
				localStorage.setItem('epimanager_info', JSON.stringify(my_info));
				console.log("Erreur de connexion à l'intra. (user)");
			}
		}
	};
	req.send(null);
}

function update_planning() {
	let today = new Date();
	let nextWeek = new Date(today.getTime() + 6 * 24 * 60 * 60 * 1000);
	let date = today.getFullYear() + '-' + (today.getMonth() + 1) + '-' + today.getDate();
	let nextDate = nextWeek.getFullYear() + '-' + (nextWeek.getMonth() + 1) + '-' + nextWeek.getDate();

	let req2 = new XMLHttpRequest();
	req2.open('GET', "https://intra.epitech.eu/planning/load?format=json&start=" + date + "&end=" + nextDate, true);
	req2.onload = function () {
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
