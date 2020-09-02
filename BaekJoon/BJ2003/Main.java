package BJ2003;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		st = new StringTokenizer(br.readLine(), " ");
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		int[] arr = new int[N+1];
		st = new StringTokenizer(br.readLine(), " ");
		arr[0] = 0;
		for (int i = 1; i <= N; i++) {
			arr[i] = arr[i-1] + Integer.parseInt(st.nextToken());
		}
		
		int Answer = 0;
		for (int i = 0; i < N; i++) {
			int j = i+1, sum = 0;
			while (j <= N && sum <= M) {
				sum = arr[j++] - arr[i];
				if (sum == M) {
					Answer++;
					break;
				}
			}
		}
		System.out.println(Answer);
	}
}
