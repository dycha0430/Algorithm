package BJ1697;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	static int N, K, Answer = 0;
	static int[] visit;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);		
		N = sc.nextInt();
		K = sc.nextInt();
		visit = new int[100001];
		Arrays.fill(visit, -1);
		BFS(N);
		System.out.println(visit[K]);
	}

	public static void BFS(int x) {
		
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(x);
		visit[x] = 0;
		
		int[] pos = new int[3];
		while (!q.isEmpty()) {
			int nx = q.poll();
			if (nx == K) return;
			pos[0] = nx+1;
			pos[1] = nx-1;
			pos[2] = nx*2;
			
			for (int i = 0; i < 3; i++) {
				if (pos[i] >= 0 && pos[i] <= 100000 && visit[pos[i]] == -1) {
					q.add(pos[i]);
					visit[pos[i]] = visit[nx] + 1;
				}
			}
		}
	}
}
