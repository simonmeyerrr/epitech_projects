exports.pauseHandler = function (req, res) {
    const size = req.body.size || 1;
    req.my_db.query("DELETE FROM pauses WHERE user_id = ? ; INSERT INTO pauses (user_id, pause_size) VALUES ( ? , ? )", [req.my_user_id, req.my_user_id, size],
        (err) => {
        if (err) {
            console.log(err);
            res.status(400);
            res.json({error: "unknown"});
        } else {
            res.status(200);
            res.json({message: "ok"});
        }
        });
};

exports.getLastPausesHandler = function (req, res) {
    req.my_db.query("" +
        "SELECT users.username, pauses.pause_size, pauses.pause_date " +
        "FROM pauses " +
        "INNER JOIN users ON pauses.user_id = users.id " +
        "WHERE pauses.user_id IN ( " +
        "   SELECT user_id " +
        "   FROM members " +
        "   WHERE active = true AND user_id != ? AND orga_id IN ( " +
        "       SELECT orga_id " +
        "       FROM members " +
        "       WHERE user_id = ? AND active = true " +
        "   ) " +
        ") " +
        "ORDER BY pauses.pause_date DESC " +
        "LIMIT 10",
        [req.my_user_id, req.my_user_id],
        (err, results) => {
            if (err) {
                console.log(err);
                res.status(400);
                res.json({error: "unknown"});
            } else {
                res.status(200);
                if (req.query.origin && req.query.origin === "Arduino") {
                    let dateobj = new Date();
                    if (results.length > 0)
                        res.send(dateobj.toISOString() + " " + results[0].pause_date.toISOString());
                    else
                        res.send("");
                } else {
                    res.json(results);
                }
            }
        });
};
