package Problem2;

import java.util.Scanner;

class Solution {
	static double Answer;

	public static void main(String args[]) throws Exception	{
		Scanner sc = new Scanner(System.in);		
		
		int T = sc.nextInt();
		
		for(int test_case = 0; test_case < T; test_case++) {
			Answer = 0;
			
			double R = sc.nextDouble();
			double S = sc.nextDouble();
			double E = sc.nextDouble();
			double N = sc.nextDouble();
			double curr = S;
			
			for (int i = 0; i < N; i++) {
				double l = sc.nextDouble();
				double r = sc.nextDouble();
				double h = sc.nextDouble();
				if (h >= R) {
					Answer += (l-R) - curr;
					Answer += 2*(h-R) + Math.PI*R + r-l;
					curr = r+R;
				} else {
					double dist = Math.sqrt(2*R*h-h*h);
					Answer += (l-dist) - curr;
					Answer += Math.acos(1-h/R)*R*2 + r-l;
					curr = r+dist;
				}
			}
			
			Answer += E - curr;
			
			System.out.println("Case #"+(test_case+1));
			System.out.println(Answer);
		}
	}
}