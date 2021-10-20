
function solution(answers) {
	    let answer = [];
	    let num = [0, 0, 0];
	    
	    const pick_max = [5, 8, 10];
	    const pick = [ [1, 2, 3, 4, 5], [2, 1, 2, 3, 2, 4, 2, 5], [3, 3, 1, 1, 2, 2, 4, 4, 5, 5] ]
	    
	    answers.map((ans, index) => {
		            for (let i = 0; i < 3; i++) {
				                if (ans === pick[i][index % pick_max[i]]) num[i]++;
				            }
		        });
	    
	    let max = Math.max(num[0], num[1], num[2]);

	    num.map((result, index) => {
		            if (result == max) answer.push(index+1);
		        })
	    
	    return answer;
}
