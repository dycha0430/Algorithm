let fs = require('fs');
let input = fs.readFileSync('input.txt').toString().split('\n');

let n = input[0];
let pos_ints = [];
let neg_ints = [];
let answer = 0;
for (let i = 1; i <= n; i++) {
    if (input[i] <= 0) {
        neg_ints.push(input[i]);
    } else if (input[i] != 1) {
        pos_ints.push(input[i]);
    } else {
        answer += 1;
    }
}

pos_ints.sort((a, b) => b - a);
neg_ints.sort((a, b) => a - b);

if (pos_ints.length == 1) {
    answer += Number(pos_ints[0]);
} else if (pos_ints.length > 1) {
    for (let i = 0; i < parseInt(pos_ints.length / 2); i++) {
        answer += Number(pos_ints[i * 2] * pos_ints[i * 2 + 1]);
    }

    if (pos_ints.length % 2 != 0) {
        answer += Number(pos_ints[pos_ints.length - 1]);
    }
}

if (neg_ints.length == 1) {
    answer += Number(neg_ints[0]);
} else if (neg_ints.length > 1) {
    for (let i = 0; i < neg_ints.length / 2; i++) {
        answer += Number(neg_ints[i * 2] * neg_ints[i * 2 + 1]);
    }

    if (neg_ints.length % 2 != 0) {
        answer += Number(neg_ints[neg_ints.length - 1]);
    }
}

console.log(answer);
