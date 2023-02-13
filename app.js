const {startDB} = require("./db/connect");
const express = require("express");
require("dotenv").config();
const router = require("./routes/routes");
const app = express();
const port = process.env.PORT || 5000;
app.use(express.json());

app.use("/", router);
const start = async () => {
    try {
        await startDB(process.env.MONGO_URI);
        app.listen(port, () => {
            console.log("Started server on port " + port);
        })
    } catch (e) {
        console.log(e);
    }
}

start();