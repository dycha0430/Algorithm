package Problem2_2;

import java.util.Scanner;

public class Solution {
	static int Answer;
	static int[] a, b, original;
	static int[][] reverse;
	static int n;
	
	public static void main(String args[]) throws Exception	{
		Scanner sc = new Scanner(System.in);
		a = new int[5000];
		b = new int[5000];
		
		int T = sc.nextInt();
		for(int test_case = 0; test_case < T; test_case++) {
			original = new int[5000];
			reverse = new int[5000][5000];
			n = sc.nextInt();
			int i, j, sim = 0, max = 0;
			for (i = 0; i < n; i++) {
				a[i] = sc.nextInt();
			}
			
			b[0] = sc.nextInt();
			if (a[0] == b[0]) original[0] = 1;
			
			for (i = 1; i < n; i++) {
				b[i] = sc.nextInt();
				if (a[i] == b[i]) original[i] = original[i-1] + 1;
				else original[i] = original[i-1];
			}

			max = original[n-1];
			
			for (j = 0; j < n; j++) {
				for (i = 0; i <= j; i++) {
					sim = 0;
					if (i == j) {
						reverse[i][j] = a[i]==b[i] ? 1 : 0;
					}
					else if (i+1 == j) {
						reverse[i][j] = a[i]==b[j] ? reverse[i][j] + 1 : reverse[i][j];
						reverse[i][j] = a[j]==b[i] ? reverse[i][j] + 1 : reverse[i][j];
					} else {
						if (a[i] == b[j] && a[j] == b[i]) reverse[i][j] = 2;
						else if (a[i] == b[j] || a[j] == b[i]) reverse[i][j] = 1;
						reverse[i][j] += reverse[i+1][j-1];
					}
					
					if (i != 0) sim = original[i-1];
					sim += (original[n-1] - original[j]) + reverse[i][j];
					
					if (max < sim) {
						max = sim;
					}
				}
			}
			
			System.out.println("Case #"+(test_case+1));
			System.out.println(max);
		}
	}
}
