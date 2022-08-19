
let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

let N = input[0];
let array = input[1].split(' ');
let sorted_array = array.slice().sort((a, b) => a - b);
let answer = [];

array.forEach(num => {
    let index = sorted_array.indexOf(num);
    sorted_array[index] = -1;
    answer.push(index); 
});

console.log(answer.join(" "));