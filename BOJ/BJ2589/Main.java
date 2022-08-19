package BJ2589;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	static int hori, verti, Answer = 0;
	static char[][] map;
	static int[] nx = {1, -1, 0, 0};
	static int[] ny = {0, 0, 1, -1};
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		hori = sc.nextInt();
		verti = sc.nextInt();
		map = new char[hori][verti];
		
		for (int i = 0; i < hori; i++) {
			String tmp = sc.next();
			for (int j = 0; j < verti; j++) {
				map[i][j] = tmp.charAt(j);
			}
		}
		
		for (int i = 0; i < hori; i++) {
			for (int j = 0; j < verti; j++) {
				if (map[i][j] == 'L') {
					BFS(i, j);
				}
			}
		}
		
		System.out.println(Answer);
	}

	public static void BFS(int i, int j) {
		Queue<Integer> q1 = new LinkedList<>();
		Queue<Integer> q2 = new LinkedList<>();
		
		q1.offer(i);
		q2.offer(j);
		int[][] dist = new int[hori][verti];
		int x, y, dx = 0, dy = 0;
		boolean[][] visit = new boolean[hori][verti];
		visit[i][j] = true;
		int ax = i, ay = j;
		
		while (!q1.isEmpty() && !q2.isEmpty()) {
			x = q1.poll();
			y = q2.poll();
			
			for (int k = 0; k < 4; k++) {
				dx = x+nx[k];
				dy = y+ny[k];
				if (dx >= 0 && dx < hori && dy >= 0 && dy < verti && map[dx][dy] == 'L' && visit[dx][dy] == false) {
					q1.offer(dx);
					q2.offer(dy);
					visit[dx][dy] = true;
					dist[dx][dy] = dist[x][y] + 1;
					ax = dx;
					ay = dy;
				}
			}
		}
		
		int a = dist[ax][ay];
		if (Answer < a) Answer = a;
	}
}
