package Problem2_3;

import java.util.Scanner;

class Boundary{
	int upper;
	int lower;
}

public class Solution {

	public static void main(String args[]) throws Exception	{
		Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		for(int test_case = 0; test_case < T; test_case++) {
			int L = sc.nextInt();
			int S = sc.nextInt();
			int E = sc.nextInt();
			int A = sc.nextInt();
			Boundary[] Answer = new Boundary[L];
			Boundary[] bound = new Boundary[L];
			for (int i = 0; i < L; i++) {
				Answer[i] = new Boundary();
				bound[i] = new Boundary();
			}
			
			int length = 0, j = 0, height = 0;
			
			for (int i = 0; i < A; i++) {
				length += sc.nextInt();
				height = sc.nextInt();
				
				for (; j < length; j++){
					bound[j].upper = height;
				}
			}
			
			int B = sc.nextInt();
			int[] lower = new int[L];
			j = 0; length = 0;
			for (int i = 0; i < B; i++) {
				length += sc.nextInt();
				height = sc.nextInt();
				for (; j < length; j++){
					bound[j].lower = height;
				}
			}
			
			int x = 0;
			int y = S;
			while (x < L) {
				while (x < L && bound[x].upper >= y && bound[x].lower <= y) {
					Answer[x].upper = y;
					x++;
				}
				while (x < L && bound[x].upper < y) {
					y = bound[x].upper;
					Answer[x].upper = y;
					x++;
				}
				while (x < L && bound[x].lower > y) {
					y = bound[x].lower;
					Answer[x].upper = y;
					x++;
				}
			}
			
			x = L-1; y = E;
			while (x >= 0) {
				while (x >= 0 && bound[x].upper >= y && bound[x].lower <= y) {
					Answer[x].lower = y;
					x--;
				}
				while (x >= 0 && bound[x].upper < y) {
					y = bound[x].upper;
					Answer[x].lower = y;
					x--;
				}
				while (x >= 0 && bound[x].lower > y) {
					y = bound[x].lower;
					Answer[x].lower = y;
					x--;
				}
			}
			
			int area = 0;
			for (int i = 0; i < L; i++) {
				area += Math.abs(Answer[i].upper - Answer[i].lower);
			}
			
			System.out.println("Case #"+(test_case+1));
			System.out.println(area);
		}
	}
}
