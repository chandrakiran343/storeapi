/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let currentPrice, hold = +Infinity,profit = 0, profits = [];

    for (let i = 0; i < prices.length; i++){
        currentPrice = prices[i];
        // console.log(currentPrice, hold, profit);
        if (currentPrice <= hold) {
            if (profit > 0) {
                profits.push(profit)
                profit = 0;
            }
            hold = currentPrice;
        }
        if (currentPrice === hold)
            continue;
        
        if (currentPrice - hold > profit) {
            profit = currentPrice - hold; // 1 
        }
        else {
            profits.push(profit);
            profit = 0;
            hold = currentPrice;
        }
    }
    profits.push(profit);
    return profits.reduce((a,b)=>a+b,0);
};

console.log(maxProfit([1, 2, 4, 2, 5, 7, 2, 4, 9, 0]));