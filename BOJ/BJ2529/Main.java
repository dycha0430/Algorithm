package BJ2529;

import java.util.Scanner;

public class Main {
	static int k;
	static char[] Max = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};
	static char[] min = {'9', '9', '9', '9', '9', '9', '9', '9', '9', '9'};
	static char[] inEqual, integer;
	static int[] visit;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		k = sc.nextInt();
		inEqual = new char[k];
		integer = new char[10];
		visit = new int[10];
		
		for (int i = 0; i < k; i++) {
			inEqual[i] = sc.next().charAt(0);
		}
		
		for (int i = 0; i < 10; i++) {
			visit[i] = 1;
			solve(0, i);
			visit[i] = 0;
		}
		
		
		for (int i = 0; i <= k; i++) System.out.print(Max[i]);
		System.out.println();
		for (int i = 0; i <= k; i++) System.out.print(min[i]); 
	}
	
	private static void solve(int depth, int num) {
		integer[depth] = (char) (num + '0');
		if (depth == k) {
			for (int i = 0; i <= k; i++) {
				if (Max[i] > integer[i]) break;
				else if (Max[i] < integer[i]) {
					for (int j = 0; j <= k; j++) Max[j] = integer[j];
				}
			}
			
			for (int i = 0; i <= k; i++) {
				if (min[i] < integer[i]) break;
				else if (min[i] > integer[i]) {
					for (int j = 0; j <= k; j++) min[i] = integer[i];
				}
			}
			
			return;
		}
		
		char symbol = inEqual[depth];
		for (int i = 0; i < 10; i++) {
			if (visit[i] == 0) {
				if (symbol == '<' && num < i) {
					visit[i] = 1;
					solve(depth+1, i);
					visit[i] = 0;
				}
				else if (symbol == '>' && num > i) {
					visit[i] = 1;
					solve(depth+1, i);
					visit[i] = 0;
				}
			}
		}
	}
}
