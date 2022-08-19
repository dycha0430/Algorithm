package BJ7576;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Pos{
	int row;
	int col;
	int day;
	
	public Pos(int i, int j, int day) {
		row = i;
		col = j;
		this.day = day;
	}
}

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Queue<Pos> q = new LinkedList<Pos>();
		
		int N = sc.nextInt();
		int M = sc.nextInt();
		int[][] box = new int[M][N];
		int days = 0;
		
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				box[i][j] = sc.nextInt();
				if (box[i][j] == 1) {
					q.add(new Pos(i, j, 0));
				}
			}
		}
		
		while (!q.isEmpty()) {
			Pos tmp = q.poll();
			int x = tmp.row;
			int y = tmp.col;
			days = tmp.day;
			
			int[] nx = {x+1, x-1, x, x};
			int[] ny = {y, y, y+1, y-1};
			for (int i = 0; i < 4; i++) {
				if (nx[i] >= 0 && nx[i] < M && ny[i] >= 0 && ny[i] < N && box[nx[i]][ny[i]] == 0) {
					q.add(new Pos(nx[i], ny[i], tmp.day+1));
					box[nx[i]][ny[i]] = 1;
				}
			}
		}
		
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (box[i][j] == 0) {
					days = -1;
				}
			}
		}
		
		System.out.println(days);
	}
}
