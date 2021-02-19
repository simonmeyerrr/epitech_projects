const time_int = [1, 5, 10]
var actual_day = "";
var actual_settings = 1;
var notified = [];
setInterval(check_notif, 5000);

function check_notif() {
	if (JSON.parse(localStorage.getItem('epimanager_planning')).date[0] != actual_day) {
		actual_day = JSON.parse(localStorage.getItem('epimanager_planning')).date[0];
		notified = [];
	}
	if (JSON.parse(localStorage.getItem('epimanager_settings')).time_notif != actual_settings) {
		actual_settings = JSON.parse(localStorage.getItem('epimanager_settings')).time_notif;
		notified = [];
	}
	let acti_today = JSON.parse(localStorage.getItem('epimanager_planning')).planning[0];
	for (let i = 0 ; i < acti_today.length ; i++) {
		if (is_notif_needed(acti_today[i])) {
			if (typeof InstallTrigger !== 'undefined') {
				create_notif_firefox(acti_today[i]);
			} else {
				create_notif(acti_today[i]);
			}
		}
	}
}

function is_notif_needed(acti) {
	for (let i = 0 ; i < notified.length ; i++) {
		if (notified[i] === acti.link) {
			return false;
		}
	}
	let now = new Date();
	let dif = time_dif(now.getHours(), now.getMinutes(), Number(acti.start.split(":")[0]), Number(acti.start.split(":")[1]));
	if (dif <= time_int[actual_settings] && dif > -2) {
		return true;
	} else {
		return false;
	}
}

function time_dif(hour1, minute1, hour2, minute2) {
	let time1 = hour1 * 60 + minute1;
	let time2 = hour2 * 60 + minute2;
	return (time2 - time1);
}

function create_notif_firefox(acti) {
	notified.splice(0, 0, acti.link);
	browser.notifications.create(
		acti.link,
		get_option_firefox(acti)
	)
}

function get_option_firefox(acti) {
	return {
    type: "basic",
    message: "Activité à " + acti.start + " dans la salle " + acti.room,
    title: acti.name,
    iconUrl: "128.png"
  };
}

function create_notif(acti) {
	notified.splice(0, 0, acti.link);
	new Notification(acti.name, get_option(acti));
}

function get_option(acti) {
	return {
    body: "Activité à " + acti.start + " dans la salle " + acti.room,
    icon: "128.png",
    tag:  acti.link
  };
}
