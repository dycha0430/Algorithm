package BJ1205;

import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N, newScore, P;
		int[] score;

		N = sc.nextInt(); //리스트에 있는 점수의 개수
		newScore = sc.nextInt();
		P = sc.nextInt(); //리스트에 올라갈 수 있는 개수
		
		score = new int[N+1];
		score[N] = -1;
		
		for (int i = 0; i < N; i++) {
			score[i] = sc.nextInt();
		}

		int i = 0;
		while (score[i] > newScore) i++;
		
		int j = i;
		while (score[j] >= newScore) j++;
		
		if (j == P) System.out.println(-1);
		else System.out.println(i+1);
	}	
}
