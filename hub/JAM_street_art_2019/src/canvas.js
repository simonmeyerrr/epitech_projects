const {Mutex} = require('async-mutex');
const { createCanvas } = require('canvas');
const canvas = createCanvas(800, 400);
const ctx = canvas.getContext('2d');
clearCanvas();

let lastUpdate = Date.now();
let mutex = new Mutex();

function drawLine(from, to, color, width) {
    ctx.beginPath();
    ctx.fillStyle = color;
    ctx.strokeStyle = color;
    ctx.lineWidth = width;
    ctx.moveTo(from[0], from[1]);
    ctx.lineTo(to[0], to[1]);
    ctx.stroke();
    ctx.fill();
    ctx.closePath();
    drawLineCircle([to[0] - width / 4 / 2, to[1] - width / 4 / 2], color, width / 4);
}

function drawLineCircle(pos, color, width) {
    ctx.beginPath();
    ctx.fillStyle = color;
    ctx.strokeStyle = color;
    ctx.lineWidth = width;
    ctx.arc(pos[0], pos[1], width, 0, 2 * Math.PI, true);
    ctx.stroke();
    ctx.fill();
    ctx.closePath();
}

function drawCircle(pos, color, width) {
    ctx.beginPath();
    ctx.fillStyle = color;
    ctx.strokeStyle = color;
    ctx.lineWidth = 0;
    ctx.arc(pos[0], pos[1], width, 0, 2 * Math.PI, true);
    ctx.stroke();
    ctx.fill();
    ctx.closePath();
}

function drawRectangle(from, to, color, width) {
    ctx.beginPath();
    ctx.strokeStyle = color;
    ctx.lineWidth = width;
    ctx.fillStyle = color;
    ctx.rect(from[0], from[1], to[0] - from[0], to[1] - from[1]);
    ctx.fill();
    ctx.stroke();
    ctx.closePath();
}

function clearCanvas() {
    ctx.beginPath();
    ctx.fillStyle = "#ffffff";
    ctx.strokeStyle = "#ffffff";
    ctx.fillRect(0, 0, canvas.width, canvas.height);
    ctx.stroke();
    ctx.closePath();
}

function execute(type, data) {
    try {
        if (type === "line") {
            drawLine(data.from, data.to, data.color, data.width);
        } else if (type === "circle") {
            drawCircle(data.pos, data.color, data.width);
        } else if (type === "clear") {
            clearCanvas();
        } else if (type === "rectangle") {
            drawRectangle(data.from, data.to, data.color, data.width);
        } else {
            throw "Invalid type: " + type;
        }
    } catch (e) {
        console.log(e);
        return;
    }
    lastUpdate = Date.now();
}

function executeMutex(type, data) {
    mutex.acquire().then((release) => {
        execute(type, data);
        release();
    });
}

module.exports = {
    getLastUpdate: () => lastUpdate,
    getDataUrl: () => canvas.toDataURL(),
    execute: execute
};