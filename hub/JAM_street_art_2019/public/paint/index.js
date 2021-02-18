//----------------------------------------------------------------\\

// Init Websocket
let ws = new WebSocket('ws://' + window.location.hostname + ':' + window.location.port + '/websocket');
document.getElementById("status").innerHTML = 'connecting';

function send(type, data) {
    ws.send(JSON.stringify({type, data}));
}

ws.onerror = (e) => {
    ws.close();
    console.log(e);
};

ws.onclose = (e) => {
    document.getElementById("status").innerHTML = 'disconnected';
};

ws.onopen = () => {
    document.getElementById("status").innerHTML = 'connected';
};

//----------------------------------------------------------------\\

// Init drawing information

let canvas,
    ctx,
    action = "line",
    is_drawing = false,
    from = [0, 0],
    to = [0, 0],
    color= "#000000",
    width= 5,
    img = new Image
;

function SelectTool(tool) {
    action = tool;
    if (tool === "line")
        document.getElementById("slider").style.left = "0%";
    if (tool === "rectangle")
        document.getElementById("slider").style.left = "50%";
    if (tool === "circle")
        document.getElementById("slider").style.left = "25%";
}

function init() {
    canvas = document.getElementById('canvas');
    ctx = canvas.getContext("2d");
    img.onload = function(){ctx.drawImage(img,0,0);};

    canvas.addEventListener("mousemove", moveDraw);
    canvas.addEventListener("mousedown", startDraw);
    canvas.addEventListener("mouseup", stopDraw);
    canvas.addEventListener("mouseout", stopDraw);
}

function rgb2hex(rgb) {
    if (/^#[0-9A-F]{6}$/i.test(rgb)) return rgb;
    rgb = rgb.substring(0, rgb.indexOf(')') + 1);
    rgb = rgb.match(/^rgb\((\d+),\s*(\d+),\s*(\d+)\)$/);
    function hex(x) {
        return ("0" + parseInt(x).toString(16)).slice(-2);
    }
    return "#" + hex(rgb[1]) + hex(rgb[2]) + hex(rgb[3]);
}

function startDraw(e) {
    from = [e.offsetX, e.offsetY];
    to = from;
    is_drawing = true;
}

function stopDraw(e) {
    if (!is_drawing) return;
    is_drawing = false;
    if (action === "line") {
        from = to;
        to = [e.offsetX, e.offsetY];
        send("line", {from: from, to: to, color: color, width: width});
    } else if (action === "circle") {
        send("circle", {pos: from, color: color, width: Math.sqrt((from[0] - to[0]) ** 2 + (from[1] - to[1]) ** 2)});
    } else if (action === "rectangle") {
        send("rectangle", {from: from, to: to, color: color, width: width});
    }
}

function moveDraw(e) {
    if (!is_drawing) return;
    if (action === "line") {
        let tmp_from = to;
        let tmp_to = [e.offsetX, e.offsetY];
        const dist = Math.sqrt((tmp_from[0] - tmp_to[0]) ** 2 + (tmp_from[1] - tmp_to[1]) ** 2);
        if (dist > 8) {
            from = to;
            to = [e.offsetX, e.offsetY];
            send("line", {from: from, to: to, color: color, width: width});
        }
    } else if (action === "circle") {
        ctx.beginPath();
        ctx.fillStyle = "#ffffff";
        ctx.strokeStyle = "#ffffff";
        ctx.fillRect(0, 0, canvas.width, canvas.height);
        ctx.stroke();
        ctx.closePath();
        ctx.drawImage(img,0,0);
        ctx.beginPath();
        to = [e.offsetX, e.offsetY];
        let dist = Math.sqrt((from[0] - to[0]) ** 2 + (from[1] - to[1]) ** 2);
        ctx.strokeStyle = color;
        ctx.lineWidth = 0;
        ctx.fillStyle = color;
        ctx.arc(from[0], from[1], dist, 0, Math.PI * 2);
        ctx.fill();
        ctx.stroke();
        ctx.closePath();
    } else if (action === "rectangle") {
        ctx.beginPath();
        ctx.fillStyle = "#ffffff";
        ctx.strokeStyle = "#ffffff";
        ctx.fillRect(0, 0, canvas.width, canvas.height);
        ctx.stroke();
        ctx.closePath();
        ctx.drawImage(img,0,0);
        ctx.beginPath();
        ctx.strokeStyle = color;
        ctx.lineWidth = width;
        ctx.fillStyle = color;
        to = [e.offsetX, e.offsetY];
        ctx.rect(from[0], from[1], to[0] - from[0], to[1] - from[1]);
        ctx.fill();
        ctx.stroke();
        ctx.closePath();
    }
}

// on click clear button
function clearCanvas() {
    send("clear", 0);
}

// on color selection
function selectColor(obj) {
    color = rgb2hex(obj.style.background);
    document.getElementById("colorSelected").style.background = color;
}

function selectSize(obj) {
    width = obj.value;
    document.getElementById("sizeText").innerText = width;
}

// Messages from websocket
ws.onmessage=function(ms)
{
    let msg = JSON.parse(ms.data);

    if (msg.type === "players") {
        document.getElementById("players").innerHTML = msg.data;
    } else if (msg.type === "canvas") {
        img.src = msg.data;
        if (is_drawing && action === "circle") {
            ctx.beginPath();
            ctx.fillStyle = "#ffffff";
            ctx.strokeStyle = "#ffffff";
            ctx.fillRect(0, 0, canvas.width, canvas.height);
            ctx.stroke();
            ctx.closePath();
            ctx.drawImage(img,0,0);
            ctx.beginPath();
            let dist = Math.sqrt((from[0] - to[0]) ** 2 + (from[1] - to[1]) ** 2);
            ctx.strokeStyle = color;
            ctx.lineWidth = 0;
            ctx.fillStyle = color;
            ctx.arc(from[0], from[1], dist, 0, Math.PI * 2);
            ctx.fill();
            ctx.stroke();
            ctx.closePath();
        } else if (is_drawing && action === "rectangle") {
            ctx.beginPath();
            ctx.fillStyle = "#ffffff";
            ctx.strokeStyle = "#ffffff";
            ctx.fillRect(0, 0, canvas.width, canvas.height);
            ctx.stroke();
            ctx.closePath();
            ctx.drawImage(img,0,0);
            ctx.beginPath();
            ctx.strokeStyle = color;
            ctx.lineWidth = width;
            ctx.fillStyle = color;
            ctx.rect(from[0], from[1], to[0] - from[0], to[1] - from[1]);
            ctx.fill();
            ctx.stroke();
            ctx.closePath();
        }
        send("recv", 1);
    } else if (msg.type === "ping") {
        send("pong", 0);
    } else {
        console.log("Unkown message type:", msg.type);
    }
};