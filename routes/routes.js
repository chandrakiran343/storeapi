const express = require("express");
const router = express.Router();
const { getProducts, createProduct, getProduct } = require("../controllers/products");

router.get("/", getProducts).post("/", createProduct);

router.get("/:id", getProduct)


module.exports = router;