const uuid = require('uuid');
const canvas = require("./canvas");

let lastSend = Date.now();

// Total connections
let connections = {};

function send(ws, msg) {
    if (msg.type === "canvas") {
        if (ws.lastRecv === 0) {
            return;
        } else {
            ws.lastRecv = 0;
        }
    }
    ws.send(JSON.stringify(msg));
}

function broadcast(msg) {
    for (let [id, connection] of Object.entries(connections)) {
        send(connection, msg);
    }
}

function addConnection(ws) {
    connections[ws.uuid] = ws;
    console.log("[+]", ws.uuid);
    broadcast({type: "players", data: Object.keys(connections).length});
    send(ws, {type: "canvas", data: canvas.getDataUrl()});
}

function removeConnection(ws) {
    delete connections[ws.uuid];
    console.log("[-]", ws.uuid);
    broadcast({type: "players", data: Object.keys(connections).length});
}

setInterval(() => {
    if (canvas.getLastUpdate() > lastSend) {
        lastSend = Date.now();
        broadcast({type: "canvas", data: canvas.getDataUrl()});
    }
}, 150);

setInterval(() => {
    broadcast({type: "ping", data: 0});
}, 5000);

function handler(ws, req) {
    ws.uuid = uuid.v4();
    ws.lastRecv = 1;
    addConnection(ws);

    ws.on('message', function(msg) {
        //console.log("[*]", ws.uuid, msg);
        msg = JSON.parse(msg);
        if (msg.type === "recv")
            ws.lastRecv = 1;
        else if (msg.type !== "pong")
            canvas.execute(msg.type, msg.data);
    });

    ws.on('error', function(e) {
        console.log("[!]", ws.uuid, e);
    });

    ws.on('close', function() {
        removeConnection(ws);
    });
}

module.exports = handler;