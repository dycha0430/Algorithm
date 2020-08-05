import java.util.Scanner;

public class Main {
	static int N, num = 0;
	static int[][] computers = new int[101][101];
	static int[] connected = new int[101];
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int M, u, v;
		
		N = sc.nextInt();
		M = sc.nextInt();
		for (int i = 0; i < M; i++) {
			u = sc.nextInt();
			v = sc.nextInt();
			computers[u][v] = 1;
			computers[v][u] = 1;
		}
		virus(1);
		connected[1] = 0;
		
		for (int  i = 1; i <= N; i++) {
			if (connected[i] == 1)
				num++;
		}
		
		System.out.println(num);
	}
	
	public static void virus(int k) {
		for (int i = 1; i <= N; i++) {
			if (computers[k][i] == 1) {
				computers[k][i] = 0;
				computers[i][k] = 0;
				connected[i] = 1;
				virus(i);
			}
		}
	}
}
