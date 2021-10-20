function solution(priorities, location) {
	    var answer = 0;
	    
	    let print_idx = 0;
	    while (priorities.length != 0) {
		            for (let i = print_idx, j = 0; j < priorities.length; j++) {
				                if (priorities[print_idx] < priorities[i]) {
							                print_idx = i;
							            }
				                i = (i+1) % priorities.length;
				            }
		            
		            answer++;
		            if (print_idx === location) break;
		            priorities[print_idx] = 0;
		        }
	    return answer;
}
