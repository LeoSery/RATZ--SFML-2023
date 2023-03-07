"use strict";
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const express_1 = __importDefault(require("express"));
const os_1 = __importDefault(require("os"));
//require('dotenv').config({path: 'src/.env'});
const app = (0, express_1.default)();
const port = process.env.PING_LISTEN_PORT;
app.use(express_1.default.json());
const pg_1 = require("pg");
const pool = new pg_1.Pool({
    host: process.env.DB_HOST,
    user: process.env.DB_USER,
    database: process.env.DB_NAME,
    password: process.env.DB_PASSWORD,
    port: parseInt(process.env.DB_PORT || "5432")
});
const connectToDB = () => __awaiter(void 0, void 0, void 0, function* () {
    try {
        yield pool.connect();
        console.log('connected');
    }
    catch (err) {
        console.log(err);
    }
});
connectToDB();
pool
    .query('SELECT $1::text as name', ['brianc'])
    .then((res) => console.log(res.rows[0].name))
    .catch((err) => console.error('Error executing query', err.stack));
app.get('/scorelist', (req, res) => {
    pool
        .query('SELECT * FROM Players')
        .then((results) => {
        console.log(results.rows);
        res.json(results.rows);
    })
        .catch((err) => console.error('Error executing query', err.stack));
});
app.put('/newscore', (req, res) => {
    console.log('New Score request on process: ' + os_1.default.hostname());
    console.log(req.body);
    const pseudo = req.body.pseudo;
    const score = req.body.score;
    console.log(pseudo, score);
    try {
        pool
            .query(`UPDATE Players SET score=${score} WHERE pseudo='${pseudo}';`)
            .then((results) => {
            console.log(results);
        });
    }
    catch (err) {
        console.log("not updating");
    }
    pool
        .query(`INSERT INTO Players (pseudo, score) VALUES ('${pseudo}',${score});`)
        .then((results) => {
        console.log(results);
    })
        .catch((err) => console.log("not inserting"));
});
app.listen(port, () => {
    console.log(`The application is listening on port: ${port}!`);
});
