const express = require("express");
const router = express.Router();
const { getProducts, createProduct, getProduct, getProductsTesting } = require("../controllers/products");

router.get("/", getProducts).post("/", createProduct);
// router.get("/static", getProductsStatic);
router.get("/test/", getProductsTesting);
router.get("/:id", getProduct)



module.exports = router;