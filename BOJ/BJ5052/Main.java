package BJ5052;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static int n;
	static String[] phoneNum;

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		int t = Integer.parseInt(br.readLine());
		
		for (int test_case = 0; test_case < t; test_case++) {
			boolean consistent = true;
			n = Integer.parseInt(br.readLine());
			phoneNum = new String[n];
			for (int i = 0; i < n; i++) {
				phoneNum[i] = br.readLine();
			}
			
			Arrays.sort(phoneNum);
			
			for (int i = 0; i < n-1; i++) {
				if (consistent == false) break;
				else if (phoneNum[i].length() >= phoneNum[i+1].length()) continue;
				
				if (phoneNum[i].equals(phoneNum[i+1].substring(0, phoneNum[i].length()))) {
					consistent = false;
				}
			}
			
			if (consistent) System.out.println("YES");
			else System.out.println("NO");
			
		}
	}
}
