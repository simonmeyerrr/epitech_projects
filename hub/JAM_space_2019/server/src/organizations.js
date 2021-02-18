/*

    PAUSE

*/

exports.createOrganizationHandler = function (req, res) {
    if (!req.body.name || req.body.name.length < 1) {
        res.status(200);
        res.json({error: "invalid organization name" });
        return;
    }
    req.my_db.query("INSERT INTO organizations (name) VALUES (?)", [req.body.name], function(err, result) {
        if (err) {
            res.status(400);
            res.json({ message: "Organization " + req.body.name + " creating failed." });
        } else {
            req.my_db.query("INSERT INTO members (user_id, orga_id) VALUES (?, ?)", [req.my_user_id, result.insertId], function(err, result) {
                if (err) {
                    res.status(400);
                    res.json({ message: "Adding user in " + req.body.name + " organization failed." });
                } else {
                    res.status(200);
                    res.json({ message: "Organization: " + req.body.name + " added." });
                }
            });
        }
    });
};

exports.inviteHandler = function (req, res) {
    req.my_db.query("SELECT id FROM members WHERE user_id = ? AND orga_id = (SELECT id FROM organizations WHERE name = ? LIMIT 1) LIMIT 1", [req.my_user_id, req.body.name], function(err, result) {
        if (err || result.length < 1) {
            res.status(400);
            res.json({ message: "You aren't part of " + req.body.name + " organization." });
        } else {
            req.my_db.query("INSERT INTO members (user_id, orga_id) VALUES ((SELECT id FROM users WHERE username = ? LIMIT 1), (SELECT id FROM organizations WHERE name = ? LIMIT 1))", [req.body.username, req.body.name], function(err, result) {
                if (err || result.length < 1) {
                    res.status(400);
                    res.json({ message: "Adding " + req.body.username + " in " + req.body.name + " organization failed." });
                } else {
                    res.status(200);
                    res.json({ message: "Adding " + req.body.username + " in " + req.body.name + " organization succeed." });
                }
            });
        }
    });
};

exports.activeHandler = function (req, res) {
    req.my_db.query("UPDATE members SET active = ? WHERE user_id = ? AND orga_id = (SELECT id FROM organizations WHERE name = ? LIMIT 1)", [req.body.active, req.my_user_id, req.body.name], function(err, result) {
        if (err) {
            res.status(400);
            res.json({ message: "Can't reach organization." });
        } else {
            res.status(200);
            if (req.body.active)
                res.json({ message: req.body.name + " organization is now active for you."});
            else
                res.json({ message: req.body.name + " organization is now unactive for you."});
        }
    });
};

exports.getMyOrganizationsHandler = function (req, res) {
    req.my_db.query("SELECT organizations.name, members.active FROM members INNER JOIN organizations ON members.orga_id=organizations.id WHERE members.user_id = ?", [req.my_user_id], function(err, result) {
        if (err) {
            res.status(400);
            res.json({ message: "Can't reach your suscribed organizations." });
        } else {
            res.status(200);
            res.json({ message: "Reach your organizations.", organizations: result});
        }
    });
};

exports.getMyOrganizationsMembersHandler = function (req, res) {
    req.my_db.query("SELECT users.username FROM members INNER JOIN users ON members.user_id=users.id WHERE orga_id = (SELECT id FROM organizations WHERE name = ?)", [req.params.name], function(err, result) {
        if (err || result.length === 0) {
            res.status(400);
            res.json({ message: "Can't reach " + req.params.name + " members"});
        } else {
            res.status(200);
            res.json({ message: "Reach " + req.params.name + " members.", members: result});
        }
    });
};

exports.deleteOrganizationHandler = function (req, res) {
    req.my_db.query("DELETE FROM members WHERE user_id = ? AND orga_id = (SELECT id FROM organizations WHERE name = ?)", [req.my_user_id, req.params.name], function(err, result) {
        if (err) {
            res.status(400);
            res.json({ message: "Can't reach " + req.params.name + " organization." });
        } else {
            req.my_db.query("SELECT id FROM members WHERE orga_id = (SELECT id FROM organizations WHERE name = ?)", [req.params.name], function(err, result) {
                if (err) {
                    console.log(err);
                    res.status(400);
                    res.json({ message: "Can't reach " + req.params.name + " organization." });
                } else {
                    if (result.length > 0) {
                        res.status(200);
                        res.json({ message: "You left " + req.params.name + " organization." });
                    } else {
                        req.my_db.query("DELETE FROM organizations WHERE name = ?", [req.params.name], function(err, result) {
                            if (err) {
                                console.log(err);
                                res.status(400);
                                res.json({ message: "Can't reach " + req.params.name + " organization." });
                            } else {
                                res.status(200);
                                res.json({ message: "You left " + req.params.name + " organization and the organization has been deleted." });       
                            }
                        });
                    }
                }
            });
        }
    });
};
