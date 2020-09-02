package BJ2661;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	static int N;
	static String seq;
	static boolean stop;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		seq = "1";
		addNum(1);
	}
	
	private static void addNum(int n) {
		if (stop == true) return;
		
		if (n == N) {
			stop = true;
			System.out.println(seq);
			return;
		}
		
		String original = seq;
		for (int i = 1; i <= 3; i++) {
			seq = seq.concat(Integer.toString(i));
			
			if (seq.charAt(n) != seq.charAt(n-1) && GoodSequence()) addNum(n+1);
			
			seq = original;
		}
	}

	private static boolean GoodSequence() {
		for (int i = 1; i <= seq.length()/2; i++) {
			if (seq.substring(seq.length()-i, seq.length()).equals(seq.substring(seq.length()-i*2, seq.length()-i)))
				return false;
		}
		return true;
	}
}
