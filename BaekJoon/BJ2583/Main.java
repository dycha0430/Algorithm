import java.util.Arrays;
import java.util.Scanner;

public class Main {
	private static int[] area;
	private static int[][] paper;
	private static int tmp = -1, M, N;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int K, x1, x2, y1, y2, sep = 0;
		
		M = sc.nextInt();
		N = sc.nextInt();
		K = sc.nextInt();
		paper = new int[M][N];
		area = new int[M*N];
		
		for (int k = 0; k < K; k++) {
			x1 = sc.nextInt();
			y1 = sc.nextInt();
			x2 = sc.nextInt();
			y2 = sc.nextInt();
			for (int i = M-y2; i < M-y1; i++) {
				for (int j = x1; j < x2; j++) {
					paper[i][j] = 1;
				}
			}
		}
		
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (paper[i][j] == 0) {
					tmp++;
					sep++;
					DFS(i, j);
				}
			}
		}
		
		System.out.println(sep);
		Arrays.sort(area, 0, sep);
		for (int i = 0; i < sep; i++) {
			System.out.print(area[i] + " ");
		}
	}
	
	private static void DFS(int m, int n) {
		if (paper[m][n] == 0) {
			paper[m][n] = 1;
			area[tmp]++;
			if (m > 0)	DFS(m-1, n);
			if (n > 0)	DFS(m, n-1);
			if (n < N-1)DFS(m, n+1);
			if (m < M-1)DFS(m+1, n);
		}
	}
}
