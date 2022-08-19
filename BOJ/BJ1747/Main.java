package BJ1747;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		if (N == 1) N++;
		
		while (true) {
			if (isPrime(N) && isPalindrome(N)) {
				System.out.println(N);
				return;
			}
			N++;
		}
	}
	
	private static boolean isPrime(int num) {
		for (int i = 2; i <= Math.sqrt(num); i++) {
			if (num % i == 0) return false;
		}
		return true;
	}
	
	private static boolean isPalindrome(int num) {
		char[] numSet = String.valueOf(num).toCharArray();
		for (int i = 0; i < numSet.length/2; i++) {
			if (numSet[i] != numSet[numSet.length-1-i]) return false;
		}
		return true;
	}
}
