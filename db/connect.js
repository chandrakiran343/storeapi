const mongoose = require('mongoose');

const startDB = async (url) => {
    return mongoose.connect(url);
}

module.exports = { startDB };