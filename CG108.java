package Badminton;

import java.util.Scanner;
import java.util.StringTokenizer;

public class Solution {

	public static void main(String args[]) throws Exception	{
		Scanner sc = new Scanner(System.in);
		int winner;
		int T = sc.nextInt();
		sc.nextLine();
		for(int test_case = 0; test_case < T; test_case++) {
			winner = 0;
			String play = sc.nextLine();
			char tmp = play.charAt(play.length()-1);
			String slicer;
			if (tmp == 'B') slicer = "A";
			else slicer = "B";
			
			StringTokenizer tok = new StringTokenizer(play, slicer);
			
			while (tok.hasMoreTokens()) {
				winner += tok.nextToken().length();
			}
			String Answer = "Playing";
			System.out.println(winner);
			if (winner >= 21) {
				if (tmp == 'A') Answer = "Alice";
				else Answer = "Bob";
			}
			
			System.out.println("Case #"+(test_case+1));
			System.out.println(Answer);
		}
	}
}
