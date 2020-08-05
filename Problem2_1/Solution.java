package Problem2_1;

import java.util.Scanner;

public class Solution {
	static int Answer;
	static boolean[] prime;
	static int score;
	
	public static void main(String args[]) throws Exception	{
		Scanner sc = new Scanner(System.in);
		prime = new boolean[30001];
		
		prime[1] = true;
		for (int i = 2; i < Math.sqrt(30000); i++) {
			if (prime[i] == false) {
				for (int j = 2*i; j <= 30000; j += i)
					prime[j] = true;
			}
		}
		
		int T = sc.nextInt();
		sc.nextLine();
		
		for(int test_case = 0; test_case < T; test_case++) {
			int scoreA = 0, scoreB = 0;
			String a = sc.next();
			String b = sc.next();
			
			isPrime(a, 0);
			scoreA = score;
			score = 0;
			
			isPrime(b, 0);
			scoreB = score;
			score = 0;
			
			System.out.println(scoreA + " " + scoreB);
			
			if (scoreA == scoreB) Answer = 3;
			else if (scoreA > scoreB) Answer = 1;
			else Answer = 2;
			
			System.out.println("Case #"+(test_case+1));
			System.out.println(Answer);
		}
	}
	
	public static void isPrime(String num, int tmpScore) {
		if (prime[Integer.parseInt(num)]) {
			score = Math.max(score, tmpScore);
		} else if (num.length() == 1) {
			score = Math.max(score, tmpScore+1);
		} else {
			for (int i = 0; i < num.length(); i++) {
				String num2 = num.substring(0, i) + num.substring(i+1, num.length());
				isPrime(num2, tmpScore+1);
			}
		}
	}
}
