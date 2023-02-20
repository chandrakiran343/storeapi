const notfound = (req, res, next) => {
    res.send("<h1>Sorry, page not found</h1>");
}

class CustomError extends Error {
    constructor(message, statusCode) {
        super(message);
        this.statusCode = statusCode;
    }   
}
const createError = (message, statusCode) => {
    return new CustomError(message, statusCode);
}

const manError = (err, req, res, next) => {
    if(err instanceof CustomError)
        return res.status(err.statusCode).json({ message: err.message });
    res.status(500).json({ message: "Something went very wrong!!" });
}

module.exports = { notfound, manError, createError};