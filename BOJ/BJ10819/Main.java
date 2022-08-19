package BJ10819;

import java.util.Arrays;
import java.util.Scanner;

public class Main {
	static int N, sum1 = 0, sum2 = 0;
	static int[] A, tmp, tmp2;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt();
		A = new int[N];
		for (int i = 0; i < N; i++) {
			A[i] = sc.nextInt();
		}

		Arrays.sort(A);
		
		tmp = new int[N];
		tmp2 = new int[N];
		
		if (N%2 == 0) {
			for (int i = 0; i < N-1; i=i+2) {
				tmp[i] = A[i/2+N/2];
				tmp[i+1] = A[i/2];
			}
		} else {			
			tmp[0] = A[N/2];
			tmp[N-1] = A[N/2-1];
			tmp2[0] = A[N/2];
			tmp2[N-1] = A[N/2+1];
			for (int i = 2; i < N-2; i=i+2) {
				tmp[i] = A[N/2-1-i/2];
				tmp2[i] = A[N/2+1+i/2];
			}
			
			for (int i = 1; i < N; i=i+2) {
				tmp[i] = A[N/2+1+i/2];
				tmp2[i] = A[i/2];
			}
		}
		
		for (int i = 1; i < N; i++) {
			sum1 += Math.abs(tmp[i] - tmp[i-1]);
			sum2 += Math.abs(tmp2[i] - tmp2[i-1]);
		}
		
		System.out.println(Math.max(sum1, sum2));
	}
}
