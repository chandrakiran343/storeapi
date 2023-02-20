const {createError} = require('../middleware/customerror');
const Product = require('../models/models');
const asyncwrapper = require('../middleware/async');
const fs = require('fs');
const path = require('path');

const getProducts = asyncwrapper(async (req, res, next) => {
    // throw new Error("Something has errors");
    const { company, name, sort,fields,page,numericFilters } = req.query;
    let queryobject = {}
    if (company) queryobject.company = company;
    if (name) queryobject.name ={ $regex: name  , $options: 'i' };

    let result = Product.find({});
    if (sort) {
        let sortlist = sort.split(',').join(' ');
        result = result.sort(sortlist);
    }
    if (fields) {
        let fieldlist = fields.split(',').join(' ');
        result = result.select(fieldlist);
    }
    if (page) {
        result = result.limit(parseInt(page)*10).skip((parseInt(page)-1)*10);
    }

    const operators = {
        '>': '$gt',
        '>=': '$gte',
        '<': '$lt',
        '<=': '$lte',
        '=': '$eq',
    }
    

    const regex = /\b(<| >|>=|<=|=)\b/g;
    const filters = numericFilters.replace(regex, (match) => `-${operators[match]}-`);
    console.log(filters);
    const options = ["price", "rating", "createdAt"];

    filters.split(",").forEach((filter) => {
        const [field, operator, value] = filter.split("-");
        if (options.includes(field)) {
            result = result.where(field);
            if (operator === '$gt') result = result.gt(value);
            if (operator === '$gte') result = result.gte(value);
            if (operator === '$lt') result = result.lt(value);
            if (operator === '$lte') result = result.lte(value);
            if (operator === '$eq') result = result.eq(value);
        }
    })
    const products = await result;
    res.status(200).json(products);
});

const getProductsTesting = asyncwrapper(async (req, res, next) => {
    const {numericFilters} = req.query;
    let queryobj = {};
    const operators = {
        '>': '$gt',
        '>=': '$gte',
        '<': '$lt',
        '<=': '$lte',
        '=': '$eq',
    }

    const regex = /\b(<| >|>=|<=|=)\b/g;
    const filters = numericFilters.replace(regex, (match) => `-${operators[match]}-`);
    console.log(filters);
    const options = ["price", "rating"];

    filters.split(",").forEach((filter) => {
        const [field, operator, value] = filter.split("-");
        if (options.includes(field)) {
            queryobj[field] = { [operator]: value };
        }
    })
    const result = await Product.find(queryobj);
    res.status(200).json(result);
    // const prods = await Product.find({
    //     name: { $regex: search , $options: "i"}
    // })
    // res.status(200).json({ prods });
})
const createProduct = asyncwrapper(async (req, res, next) => {
    console.log(req.body);
    const product = new Product(req.body);
    product.save()
        .then(() => {
            res.json(product);
        })
        .catch(err => next(err));
});

const getProduct = asyncwrapper(async (req, res, next) => {
    let element;
    Product.find({ _id: req.params.id }).then(product => {
        element = product;
        res.json(product);
    }
    ).catch(err => next(err));
    if (!element) return next(createError("Product not found", 404));
});

module.exports = { getProducts, createProduct, getProduct, getProductsTesting}