package BJ1449;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static int N, L, tapeNum = 0;
	static float[] leak;
	
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		st = new StringTokenizer(br.readLine(), " ");
		N = Integer.parseInt(st.nextToken());
		L = Integer.parseInt(st.nextToken());
		
		leak = new float[N];
		st = new StringTokenizer(br.readLine(), " ");
		for (int i = 0; i < N; i++) {
			leak[i] = Float.parseFloat(st.nextToken());
		}
		
		Arrays.parallelSort(leak);
		
		float curEnd = 0;
		for (int i = 0; i < N; i++) {
			if (leak[i]+0.5 <= curEnd) continue;
			tapeNum++;
			curEnd = (float) (leak[i]-0.5+L);
		}
		
		System.out.println(tapeNum);
	}
}
