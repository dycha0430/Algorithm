import java.util.Scanner;

public class Main {	
	static int M, N;
	static int[][] field;
	
	public static void main(String[] args) {
		int T, K, x, y, num;
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		for (int tc = 0; tc < T; tc++) {
			M = sc.nextInt();
			N = sc.nextInt();
			K = sc.nextInt();
			num = 0;
			field = new int[M][N];
			for (int i = 0; i < M; i++) {
				for (int j = 0; j < N; j++)
					field[i][j] = 0;
			}
			
			for (int i = 0; i < K; i++) {
				x = sc.nextInt();
				y = sc.nextInt();
				field[x][y] = 1;
			}
			
			for (int i = 0; i < M; i++) {
				for (int j = 0; j < N; j++) {
					if (field[i][j] == 1) {
						num++;
						DFS(i, j);
					}
				}
			}
			
			System.out.println(num);
		}
	}
	
	public static void DFS(int m, int n) {
		if (field[m][n] == 1) {
			field[m][n] = 0;
			if (m != M-1)
				DFS(m+1, n);
			if (m != 0)
				DFS(m-1, n);
			if (n != 0)
				DFS(m, n-1);
			if (n != N-1)
				DFS(m, n+1);
		}
	}
}