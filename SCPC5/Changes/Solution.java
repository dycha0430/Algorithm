package Changes;

import java.util.Scanner;

public class Solution {
	static int Answer;

	public static void main(String args[]) throws Exception	{
		Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		for(int test_case = 0; test_case < T; test_case++) {
			int changes = sc.nextInt();
			int ten = 0, fifty = 0, hundred = 0, fiveH = 0;
			
			while (changes >= 500) {
				fiveH++;
				changes -= 500;
			}
			while (changes >= 100) {
				hundred++;
				changes -= 100;
			}
			while (changes >= 50) {
				fifty++;
				changes -= 50;
			}
			while (changes >= 10) {
				ten++;
				changes -= 10;
			}
			
			System.out.println("Case #"+(test_case+1));
			System.out.println(ten + " " + fifty + " " + hundred + " " + fiveH);
		}
	}
}
