function solution(N, number) {
	    var answer = -1;
	    
	    let mem = new Array(8);
	    
	    for (let i = 1; i <= 8; i++) {
		            mem[i-1] = new Set();
		            
		            for (let j = 0; j < i; j++) {
				                let k = i - j;
				                if (j == 0) {
							                let mul = 1, ret = 0;
							                for (let l = 0; l < k; l++) {
										                    ret += N * mul;
										                    mul *= 10;
										                }
							                mem[i-1].add(ret);
							                if (ret == number) return i;
							            } else {
									                    mem[j-1].forEach(num => {
												                        mem[k-1].forEach(num2 => {
																                        let rets = [num+num2, num-num2, Math.floor(num/num2), num*num2];
																                        
																                        for (let ret of rets) {
																				                            if (ret != 0) mem[i-1].add(ret);
																				                        }
																                    });
												                    });
									                }
				                
				                if (mem[i-1].has(number)) return i;
				            }
		        }
	    return answer;
}
