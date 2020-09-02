package BJ1717;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int[] set;
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		st = new StringTokenizer(br.readLine(), " ");
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		set = new int[n+2];
		set[0] = -1;
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int comm = Integer.parseInt(st.nextToken());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			if (comm == 0) {
				union(a+1, b+1);
			} else{
				if (contains(a+1, b+1)) System.out.println("YES");
				else System.out.println("NO");
			}
		}
	}

	private static void union(int a, int b) {
		if (contains(a, b)) return;
		
		int rootB = b;
		while (set[rootB] != 0) {
			rootB = set[rootB];
		}
		
		int rootA = a;
		while (set[rootA] != 0) {
			int tmp = set[rootA];
			set[rootA] = rootB;
			rootA = tmp;
		}
		
		set[rootA] = rootB;
	}
	
	private static boolean contains(int a, int b) {
		int rootA = a;
		int rootB = b;
		
		while (set[rootA] != 0) {
			rootA = set[rootA];
		}
		
		while (set[rootB] != 0) {
			rootB = set[rootB];
		}
		
		
		if (rootA == rootB) return true;
		else return false;
	}
}
