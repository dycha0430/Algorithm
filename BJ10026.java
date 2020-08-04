package BJ10026;

import java.util.Scanner;

public class Main {
	static int N, normal = 0, colorWeak = 0;
	static char[][] normArea, weakArea;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		normArea = new char[N][N];
		weakArea = new char[N][N];
		sc.nextLine();
		
		String temp = null;
		for (int i = 0; i < N; i++) {
			temp = sc.nextLine();
			for (int j = 0; j < N; j++) {
				normArea[i][j] = temp.charAt(j);
				weakArea[i][j] = temp.charAt(j);
			}
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (normArea[i][j] != 'N') {
					normal++;
					normAreaNum(i, j);
				}
				if (weakArea[i][j] != 'N') {
					colorWeak++;
					weakAreaNum(i, j);
				}
			}
		}
		
		System.out.println(normal + " " + colorWeak);
	}
	
	public static void normAreaNum(int x, int y) {
		char c = normArea[x][y];
		if (c == 'N') {
			System.out.println("^^");
			return;
		}
		normArea[x][y] = 'N';
		if (x > 0 && normArea[x-1][y] == c) normAreaNum(x-1, y);
		if (x < N-1 && normArea[x+1][y] == c) normAreaNum(x+1, y);
		if (y > 0 && normArea[x][y-1] == c) normAreaNum(x, y-1);
		if (y < N-1 && normArea[x][y+1] == c) normAreaNum(x, y+1);
	}
	
	public static void weakAreaNum(int x, int y) {
		char c = weakArea[x][y];
		if (c == 'N') return;
		weakArea[x][y] = 'N';
		if (x > 0) {
			if (c == 'B') {
				if (weakArea[x-1][y] == c) weakAreaNum(x-1, y);
			} else if (weakArea[x-1][y] == 'G' || weakArea[x-1][y] == 'R') weakAreaNum(x-1, y);
		}
		
		if (x < N-1) {
			if (c == 'B') {
				if (weakArea[x+1][y] == c) weakAreaNum(x+1, y);
			} else if (weakArea[x+1][y] == 'G' || weakArea[x+1][y] == 'R') weakAreaNum(x+1, y);
		}
		
		if (y > 0) {
			if (c == 'B') {
				if (weakArea[x][y-1] == c) weakAreaNum(x, y-1);
			} else if (weakArea[x][y-1] == 'G' || weakArea[x][y-1] == 'R') weakAreaNum(x, y-1);
		}
		
		if (y < N-1) {
			if (c == 'B') {
				if (weakArea[x][y+1] == c) weakAreaNum(x, y+1);
			} else if (weakArea[x][y+1] == 'G' || weakArea[x][y+1] == 'R') weakAreaNum(x, y+1);
		}
	}
}
