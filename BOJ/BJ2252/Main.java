package BJ2252;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		st = new StringTokenizer(br.readLine(), " ");
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		ArrayList<Integer>[] compare = new ArrayList[N+1];
		int[] inDeg = new int[N+1];
		
		for (int i = 1; i <= N; i++) {
			compare[i] = new ArrayList<Integer>();
		}
		
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			compare[a].add(b);
			inDeg[b]++;
		}
		
		LinkedList<Integer> q = new LinkedList<>();
		for (int i = 1; i <= N; i++) {
			if (inDeg[i] == 0) {
				q.add(i);
				inDeg[i] = -1;
			}
		}

		while (!q.isEmpty()) {
			int person = q.poll();
			System.out.print(person + " ");
			
			for (int i = 0; i < compare[person].size(); i++) {
				int n = compare[person].get(i);
				inDeg[n]--;
				if (inDeg[n] == 0) {
					q.add(n);
					inDeg[n] = -1;
				}
			}
		}
	}	
}
