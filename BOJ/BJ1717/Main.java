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
		
		set = new int[n+1];
		
        for (int i = 0; i < n+1; i++) set[i] = -1;
        
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int comm = Integer.parseInt(st.nextToken());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			if (comm == 0) {
				union(a, b);
			} else{
				if (findRoot(a) == findRoot(b)) System.out.println("YES");
				else System.out.println("NO");
			}
		}
	}

	private static void union(int a, int b) {		
		int rootA = findRoot(a);
        int rootB = findRoot(b);
		
        if (rootA == rootB) return;
        
		if (set[rootA] < set[rootB]){
            set[rootB] = rootA;
        } else {
            if (set[rootA] == set[rootB]) --set[rootB];
            set[rootA] = rootB;
        }
	}
    
    private static int findRoot(int a){
        if (set[a] < 0) return a;
        else return set[a] = findRoot(set[a]);
    }
}
