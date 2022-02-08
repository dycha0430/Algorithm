
let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

let T = input[0];
let inputs = [];

for (let i = 1; i < input.length; i++) {
    if (input[i] !== '') {
        inputs.push(input[i].split(' '));
    }
}

for (let i = 0; i < inputs.length; i++) {
    let N = Number(inputs[i][0]);
    let M = Number(inputs[i][1]);

    let answer = 1;
    let multipleCount = 0;
    let divideCount = 0;
    if (M/2 < N) {
        multipleCount = N;
        divideCount = M - N;
    } else {
        multipleCount = M - N;
        divideCount = N;
    }
    for (let c1 = M; c1 > multipleCount; c1--) {
        answer *= c1;
    }

    for (let c2 = 1; c2 <= divideCount; c2++) {
        answer /= c2;
    }

    console.log(answer);
}