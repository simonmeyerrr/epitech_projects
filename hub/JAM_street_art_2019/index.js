const host = process.env.HOST || "localhost";
const port = process.env.PORT || 8080;
const app = require('./src/routes');

// Start server
app.listen(port, host, () => {
    console.log(`Street Art started on ${host} ${port}`);
});