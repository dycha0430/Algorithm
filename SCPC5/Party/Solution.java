package Party;

import java.util.Scanner;

public class Solution {
	static int Answer;
	static int[] price;
	
	public static void main(String args[]) throws Exception	{
		Scanner sc = new Scanner(System.in);
		price = new int[101];
		
		price[0] = 1;
		for (int i = 7; i < 101; i++) {
			if (price[i-7] == 1) price[i] = 1;
			else if (i >= 9 && price[i-9] == 1) price[i] = 1;
			else if (i >= 11 && price[i-11] == 1) price[i] = 1;
		}
		
		int T = sc.nextInt();
		for(int test_case = 0; test_case < T; test_case++) {
			int N = sc.nextInt();
			
			System.out.println("Case #"+(test_case+1));
			if (price[N] == 1) System.out.println("YES");
			else System.out.println("NO");
		}
	}
}
