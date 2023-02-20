const mongoose = require('mongoose');   

const product = new mongoose.Schema({
    name: String,
    price: Number,
    description: String,
    category: String,
    createdAt: {
        type: Date,
        default: Date.now()
    },
    company: {
        type: String,
        enum: {
            values: ['ikea', 'liddy', 'caressa', 'marcos'],
            message: '{VALUE} is not supported'
        }
    }
});

const Product = mongoose.model('Product', product);

module.exports = Product;