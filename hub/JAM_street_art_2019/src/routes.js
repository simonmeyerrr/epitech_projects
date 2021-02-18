const express = require('express');
const app = express();
const expressWs = require('express-ws')(app);
const paint = require('./paint');
const canvas = require('./canvas');
const imageDataURI = require('image-data-uri');

// Websocket for paint
app.ws('/websocket', paint);

app.get('/live.png', (req, res) => {
    res.send(imageDataURI.decode(canvas.getDataUrl()).dataBuffer);
});

// Serve files from public
app.use(express.static('public'));

module.exports = app;