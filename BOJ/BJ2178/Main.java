package BJ2178;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Pos{
	int row;
	int col;
	int num;
	
	public Pos(int row, int col) {
		this.row = row;
		this.col = col;
	}
}

public class Main {
	static int N, M;
	static int[][] maze;
	static boolean[][] visit;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		maze = new int[N][M];
		visit = new boolean[N][M];
		
		for (int i = 0; i < N; i++) {
			String tmp = sc.next();
			for (int j = 0; j < M; j++) {
				maze[i][j] = tmp.charAt(j) - '0';
			}
		}

		BFS();
		System.out.println(maze[N-1][M-1]);
	}
	
	//최단거리는 BFS가 더 적합함.
	public static void BFS() {
		Queue<Pos> q = new LinkedList<Pos>();
		q.offer(new Pos(0, 0));
		visit[0][0] = true;
		
		while (!q.isEmpty()) {
			Pos tmp = q.poll();
			int x = tmp.row;
			int y = tmp.col;
			
			if (x == N && y == M) break;
			
			int[] px = {x-1, x+1, x, x};
			int[] py = {y, y, y-1, y+1};
			
			for (int k = 0; k < 4; k++) {
				if (px[k] >= 0 && px[k] < N && py[k] >= 0 && py[k] < M && maze[px[k]][py[k]] != 0 && visit[px[k]][py[k]] == false) {
					q.offer(new Pos(px[k], py[k]));
					visit[px[k]][py[k]] = true;
					maze[px[k]][py[k]] = maze[x][y] + 1;
				}
			}
		}	
	}

	//DFS -> 시간초과
	/*
	public static void DFS(int i, int j, int num) {
		if (i == N-1 && j == M-1) {
			if (num < min) min = num;
		}
		
		int[] px = {i-1, i+1, i, i};
		int[] py = {j, j, j-1, j+1};

		for (int k = 0; k < 4; k++) {
			if (px[k] >= 0 && px[k] < N && py[k] >= 0 && py[k] < M && maze[px[k]][py[k]] == 1 && visit[px[k]][py[k]] == false) {
				visit[px[k]][py[k]] = true;
				DFS(px[k], py[k], num+1);
				visit[px[k]][py[k]] = false;
			}
		}
	}
	*/
}
