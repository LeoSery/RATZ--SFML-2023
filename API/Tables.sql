DROP TABLE Players;

CREATE TABLE Players (
    id SERIAL PRIMARY KEY NOT NULL,
    pseudo VARCHAR (255) UNIQUE NOT NULL,
    score INT NOT NULL
);

INSERT INTO Players (pseudo, score)
VALUES ('WEEEEE',153);


INSERT INTO Players (pseudo, score) VALUES ('WEEEEE', 69)
ON CONFLICT (pseudo) DO UPDATE 
  SET score = excluded.score;




SELECT * FROM Players ORDER BY score DESC;