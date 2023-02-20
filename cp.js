
function processData(input) {
    let inputs = "i am met Janice";
    let lists = inputs.split(" ");
    lists.forEach(e => {
        data = fetch(`http://130.185.118.141/tech_savishkaar?word=${e}`);
        console.log(data)
    })
    return 0;
}

// process.stdin.resume();
// process.stdin.setEncoding("ascii");
// _input = "";
// process.stdin.on("data", function (input) {
//     _input += input;
// });

// process.stdin.on("end", function () {
//     processData(_input);
// })
processData("I met Janice");