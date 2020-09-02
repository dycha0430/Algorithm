package BJ3649;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String tmp;
		while ((tmp = br.readLine()) != null) {
			int x = Integer.parseInt(tmp) * 10000000;
			int n = Integer.parseInt(br.readLine());
			
			int[] l = new int[n];
			
			for (int i = 0; i < n; i++) {
				l[i] = Integer.parseInt(br.readLine());
			}
				
			Arrays.sort(l);
				
			boolean yes = false;
			int j = n-1;
			for (int i = 0; i < n; i++) {
				if (yes) break;
				int cal = l[j] + l[i];
				while (cal >= x && j > i){
					if (cal == x) {
						System.out.println("yes " + l[i] + " " + l[j]);
						yes = true;
						break;
					}
					j--;
					cal = l[j] + l[i];
				}
			}
			
			if (!yes) System.out.println("danger");
		}
	}
}

/*
 			for (int i = 0; i < n; i++) {
				for (int j = n-1; j > i; j--) {
					int cal = l[j] + l[i];
					if (cal == x) {
						System.out.println("yes " + l[i] + " " + l[j]);
						return;
					} else if (cal > x) {
						continue;
					} else {
						break;
					}
				}
			}
 */

