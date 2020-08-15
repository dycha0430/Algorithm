package Hamberger;

import java.util.Scanner;

class Solution {
	static int Answer;

	public static void main(String args[]) throws Exception	{
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for(int test_case = 0; test_case < T; test_case++) {
			int bread = sc.nextInt();
			int meat = sc.nextInt();
			int vegt = sc.nextInt();
			int tmp = 0;

			tmp = Math.min(bread/2, meat);
			Answer = Math.min(tmp, vegt/3);
			
			System.out.println("Case #"+(test_case+1));
			System.out.println(Answer);
		}
	}
}