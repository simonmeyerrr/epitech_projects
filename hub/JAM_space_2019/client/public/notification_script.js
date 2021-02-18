setInterval(check_notif, 2000);

let tmp = new Date();
let lastDateNotif = tmp.toISOString();
let lastDateNotif2 = lastDateNotif;

function notif_me(txt) {
    if (typeof InstallTrigger !== 'undefined') {
        browser.notifications.create(
            "",
            {
                type: "basic",
                message: txt,
                title: "Pause !"
            }
        )
    } else {
        new Notification(
            "Pause !",
            {
                body: txt
            }
        );
    }
}

function check_notif() {
    let req = new XMLHttpRequest();

    if (!localStorage.getItem("token"))
        return;

    tmp = new Date();
    let myTime = tmp.toISOString();
    req.open('GET', 'https://space.omnirem.dev/api/pause', true);
    req.setRequestHeader("Authorization", localStorage.getItem("token"));

    req.onload = function(e) {
        if (req.readyState !== 4)
            return;
        if (req.status !== 200) {
            console.log("request error status: " + req.status);
            return;
        }
        let json = JSON.parse(req.responseText);

        if (json.length > 0) {
            console.log(json[0], lastDateNotif2, myTime);
            if (lastDateNotif2 < json[0].pause_date) {
                lastDateNotif2 = json[0].pause_date;
                lastDateNotif = json[0].pause_date;

                let date = new Date(json[0].pause_date);

                notif_me(date.getHours() + ":" + date.getMinutes() + " - " + json[0].username + " started a " + json[0].pause_size + " min. pause !");
                return;
            }
        }
        lastDateNotif2 = lastDateNotif;
        lastDateNotif = myTime;
    };

    req.send(null);
}
