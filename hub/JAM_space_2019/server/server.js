// Environment variables
const host = process.env.HOST || "8080";

// Require libraries
const express = require('express');
const cors = require('cors');
const bodyParser = require('body-parser');

// Require modules
const db = require('./src/database');
const auth = require('./src/auth');
const organizations = require('./src/organizations');
const pauses = require('./src/pauses');

// Creating server router
const app = express();
const myBodyParser = (req, res, next) => {
    bodyParser.json()(req, res, (err) => {
        if (err) {
            res.status(400);
            res.json({error: "invalid json body"});
        } else {
            next();
        }
    });
};

// Middleware
app.use(cors());
app.use(function (req, res, next) {
    console.log("Received request: %s %s from %s", req.method, req.originalUrl, req.headers['x-forwarded-for'] || req.ip.slice(7));
    next();
});

// API routes
app.get('/whoami', myBodyParser, db.middleware, auth.middleware, auth.whoami);

app.post('/login', myBodyParser, db.middleware, auth.loginHandler);
app.post('/register', myBodyParser, db.middleware, auth.registerHandler);

app.post('/orga', myBodyParser, db.middleware, auth.middleware, organizations.createOrganizationHandler);
app.get('/orga', myBodyParser, db.middleware, auth.middleware, organizations.getMyOrganizationsHandler);
app.delete('/orga/:name', myBodyParser, db.middleware, auth.middleware, organizations.deleteOrganizationHandler);
app.get('/orga/:name/members', myBodyParser, db.middleware, auth.middleware, organizations.getMyOrganizationsMembersHandler);
app.post('/orga/invite', myBodyParser, db.middleware, auth.middleware, organizations.inviteHandler);
app.post('/orga/active', myBodyParser, db.middleware, auth.middleware, organizations.activeHandler);

app.post('/pause', myBodyParser, db.middleware, auth.middleware, pauses.pauseHandler);
app.get('/pause', myBodyParser, db.middleware, auth.middleware, pauses.getLastPausesHandler);

// Invalid route management
app.use(function (req, res) {
   res.status(404);
   res.json({error: "invalid route"});
});

// Launching database and server
db.connect();
app.listen(host, function () {
    console.log(`Starting pause backend on ${host}`);
});