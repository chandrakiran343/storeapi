const mongoose = require('mongoose');   

const product = new mongoose.Schema({
    name: String,
    price: Number,
    description: String,
    category: String,
});

const Product = mongoose.model('Product', product);

module.exports = Product;