package BJ7562;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	static int I;
	static int sx, sy; //출발지
	static int ex, ey; //목적지
	static int[][] chess;
	static int[] dx = {1, -1, 1, -1, 2, -2, 2, -2};
	static int[] dy = {2, -2, -2, 2, 1, -1, -1, 1};
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T;
		T = sc.nextInt();		
		
		for (int i = 0; i < T; i++) {
			I = sc.nextInt();
			sx = sc.nextInt();
			sy = sc.nextInt();
			ex = sc.nextInt();
			ey = sc.nextInt();
			chess = new int[I][I];
			BFS();
			System.out.println(chess[ex][ey]-1);
		}
		
		
	}

	public static void BFS() {
		Queue<Integer> qx = new LinkedList<>();
		Queue<Integer> qy = new LinkedList<>();
		
		qx.offer(sx);
		qy.offer(sy);
		chess[sx][sy] = 1;
		
		int curX, curY;
		while (!qx.isEmpty() && !qy.isEmpty()) {
			curX = qx.poll();
			curY = qy.poll();
			for (int i = 0; i < 8; i++) {
				int nx = curX + dx[i];
				int ny = curY + dy[i];
				if (nx >= 0 && nx < I && ny >= 0 && ny < I && chess[nx][ny] == 0) {
					qx.offer(nx);
					qy.offer(ny);
					chess[nx][ny] = chess[curX][curY] + 1;
				}
			}
		}
	}
}
