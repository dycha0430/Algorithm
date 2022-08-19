package BJ1764;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		int N, M;
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());	
		String[] Answer = new String[Math.max(N, M)];
		int num = 0;
		
		Map<String, Boolean> notHeard = new HashMap<>();
		for (int i = 0; i < N; i++) {
			String tmp = br.readLine();
			notHeard.put(tmp, true);
		}
		
		for (int i = 0; i < M; i++) {
			String notSeen = br.readLine();
			if (notHeard.containsKey(notSeen)) {
				Answer[num++] = notSeen;
			}
		}
		
		Arrays.sort(Answer, 0, num);
		System.out.println(num);
		for (int i = 0; i < num; i++) {
			System.out.println(Answer[i]);
		}
	}
}
