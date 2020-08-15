package BJ2667;

import java.util.*;

public class Main {
	static int N, houseNum = 0;
	static int[][] house;
	static PriorityQueue<Integer> complex;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		house = new int[N][N];
		complex = new PriorityQueue<>();
		
		for (int i = 0; i < N; i++) {
			String tmp = sc.next();
			for (int j = 0; j < N; j++) {
				house[i][j] = tmp.charAt(j) - '0';
			}
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (house[i][j] == 1) {
					houseNum = 0;
					DFS(i, j);
					complex.add(houseNum);
				}
			}
		}
		
		System.out.println(complex.size());
		while (!complex.isEmpty()) {
			System.out.println(complex.poll());
		}
	}

	public static void DFS(int i, int j) {
		if (house[i][j] == 1) {
			house[i][j] = 0;
			houseNum++;
			if (i > 0) DFS(i-1, j);
			if (i < N-1) DFS(i+1, j);
			if (j > 0) DFS(i, j-1);
			if (j < N-1) DFS(i, j+1);
		}
	}
}
