function solution(progresses, speeds) {
	    var answer = [];
	    
	    while (progresses.length != 0) {
		            progresses.forEach((progress, index) => {
				                progresses[index] += speeds[index];
				            });
		            
		            let ans = 0;
		            while (progresses.length != 0) {
				                if (progresses[0] >= 100) {
							                ans++;
							                progresses.shift();
							                speeds.shift();
							            }
				                else break;
				            }
		            
		            if (ans != 0) answer.push(ans);
		            
		        }
	    
	    return answer;
}
