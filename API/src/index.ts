import express from 'express';
import os from 'os';
//require('dotenv').config({path: 'src/.env'});
const app = express();
const port = process.env.PING_LISTEN_PORT;

app.use(express.json());

import { Pool } from "pg";
const pool = new Pool({
  host: process.env.DB_HOST,
  user: process.env.DB_USER,
  database: process.env.DB_NAME,
  password: process.env.DB_PASSWORD,
  port: parseInt(process.env.DB_PORT || "5432")
});

const connectToDB = async () => {
  try {
    await pool.connect();
    console.log('connected');
  } catch (err) {
    console.log(err);
  }
};
connectToDB();


pool
  .query('SELECT $1::text as name', ['somequerytest'])
  .then((res) => console.log(res.rows[0].name))
  .catch((err) => console.error('Error executing query', err.stack))

  

app.get('/scorelist', (req, res) => {
  pool
  .query('SELECT * FROM Players ORDER BY score DESC')
  .then((results) => {
    console.log(results.rows);
    res.json(results.rows)
  }) 
  .catch((err) => console.error('Error executing query', err.stack))
    
    
    
})

app.get('/ping', (req, res) => {
  res.send("testoooo")
    
    
    
})


app.put('/newscore', (req, res) => {
  console.log('New Score request on process: '+os.hostname());
  console.log(req.body)
  const pseudo = req.body.pseudo;
  const score = req.body.score;
  console.log(pseudo,score)

  try {

    pool
    .query(`UPDATE Players SET score=${score} WHERE pseudo='${pseudo}';`)
    .then((results) => {
    console.log(results); 
    res.sendStatus(200)
  }) 
  } catch(err){
    console.log("not updating")
  }
  
  pool
  .query(`INSERT INTO Players (pseudo, score) VALUES ('${pseudo}',${score});`)
  .then((results) => {
    console.log(results);
    res.sendStatus(200)
  }) 
  .catch((err) => console.log("not inserting"))


  

})


app.listen( port, () => {
    
    console.log(`The application is listening on port: ${port}!`);
    
})