package BJ1987;

import java.util.Scanner;

public class Main {
	static int R, C, Answer = 1;
	static char[][] board;
	static int[] visit;
	static int[] dx = {1, -1, 0, 0};
	static int[] dy = {0, 0, 1, -1};
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		R = sc.nextInt();
		C = sc.nextInt();
		board = new char[R][C];
		visit = new int[26];
		for (int i = 0; i < R; i++) {
			String tmp = sc.next();
			for (int j = 0; j < C; j++) {
				board[i][j] = tmp.charAt(j);
			}
		}
		visit[board[0][0] - 'A'] = 1;
		solution(0, 0, 1);
		
		System.out.println(Answer);
		
	}

	private static void solution(int i, int j, int num) {
		if (Answer < num) Answer = num;
		
		for (int k = 0; k < 4; k++) {
			int nx = i + dx[k];
			int ny = j + dy[k];
			if (nx >= 0 && nx < R && ny >= 0 && ny < C && visit[board[nx][ny] - 'A'] == 0) {
				visit[board[nx][ny] - 'A'] = 1;
				solution(nx, ny, num+1);
				visit[board[nx][ny] - 'A'] = 0;
			}
		}
	}	
}
