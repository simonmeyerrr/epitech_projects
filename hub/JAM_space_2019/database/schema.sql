CREATE TABLE users (
  id         INTEGER      NOT NULL AUTO_INCREMENT,
  username   VARCHAR(256) NOT NULL,
  password   VARCHAR(256) NOT NULL,
  CONSTRAINT PRIMARY KEY (id),
  CONSTRAINT unique_user UNIQUE KEY (username)
);

CREATE TABLE organizations (
  id         INTEGER      NOT NULL AUTO_INCREMENT,
  name       VARCHAR(256) NOT NULL,
  CONSTRAINT PRIMARY KEY (id),
  CONSTRAINT unique_organization UNIQUE KEY (name)
);

CREATE TABLE members (
  id         INTEGER NOT NULL AUTO_INCREMENT,
  user_id    INTEGER NOT NULL,
  orga_id    INTEGER NOT NULL,
  active     BOOLEAN NOT NULL DEFAULT true,
  CONSTRAINT PRIMARY KEY (id),
  FOREIGN KEY (user_id) REFERENCES users(id) ON DELETE CASCADE,
  FOREIGN KEY (orga_id) REFERENCES organizations(id) ON DELETE CASCADE,
  CONSTRAINT unique_member UNIQUE (user_id, orga_id)
);

CREATE TABLE pauses (
  id         INTEGER   NOT NULL AUTO_INCREMENT,
  user_id    INTEGER   NOT NULL,
  pause_size INTEGER   NOT NULL,
  pause_date TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
  CONSTRAINT PRIMARY KEY (id)
);