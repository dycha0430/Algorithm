package BJ16282;

import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		long n = Long.parseLong(br.readLine());
		long multi = 2;
		for (int i = 2; i <= 64; i++) {
			multi *= 2;
			long sum = (multi-1)*i+i-1;
			if (sum >= n) {
				System.out.println(i-1);
				return;
			}
		}
	}
}