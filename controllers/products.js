
const Product = require('../models/models');

const getProducts = (req, res, next) => {
    console.log(req.body);
    Product.find()
        .then(products => {
            res.json(products);
        })
        .catch(err => next(err));
}

const createProduct = (req, res, next) => {
    console.log(req.body);
    const product = new Product(req.body);
    product.save()
        .then(() => {
            res.json(product);
        })
        .catch(err => next(err));
}

const getProduct = (req, res, next) => {
    console.log(req.body);
    Product.find({ _id: req.params.id }).then(product => {
        res.json(product);
    }
    ).catch(err => next(err));
}

module.exports = { getProducts, createProduct, getProduct}