package BJ1260;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	static int N, M, V;
	static int[] visit;
	static int[][] edge;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt();
		M = sc.nextInt();
		V = sc.nextInt();
		
		edge = new int[N+1][N+1];
		
		for (int i = 0; i < M; i++) {
			int s = sc.nextInt();
			int e = sc.nextInt();
			edge[s][e] = 1;
			edge[e][s] = 1;
		}
		
		visit = new int[N+1];
		DFS(V);
		System.out.println();
		visit = new int[N+1];
		BFS(V);
	}
	
	public static void DFS(int v0) {
		visit[v0] = 1;
		System.out.print(v0 + " ");
		for (int i = 1; i <= N; i++) {
			if (edge[v0][i] == 1 && visit[i] == 0) {
				DFS(i);
			}
		}
	}
	
	public static void BFS(int v0) {
		Queue<Integer> q = new LinkedList<Integer>();
		
		q.add(v0);
		visit[v0] = 1;
		
		while (!q.isEmpty()) {
			int tmp = q.poll();
			System.out.print(tmp + " ");
			
			for (int i = 1; i <= N; i++) {
				if (edge[tmp][i] == 1 && visit[i] == 0) {
					q.add(i);
					visit[i] = 1;
				}
			}
		}
	}
}
