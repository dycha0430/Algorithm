package BJ1759;

import java.util.Arrays;
import java.util.Scanner;

public class Main {
	static int L, C;
	static char[] alphabets;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		L = sc.nextInt();
		C = sc.nextInt();
		alphabets = new char[C];
		
		for (int i = 0; i < C; i++) {
			String tmp = sc.next();
			alphabets[i] = tmp.charAt(0);
		}
		
		Arrays.sort(alphabets);
		
		char[] passWord = new char[L];
		
		Combi(passWord, 0, 0, 0, 0);
	}
	
	private static void Combi(char[] passWord, int index, int start, int con, int vow){
		if (index == L) {
			if (con > 1 && vow > 0) {
				for (int i = 0; i < L; i++) System.out.print(passWord[i]);
				System.out.println();
			}
			return;
		}
		
		for (int i = start; i < C-L+1+index; i++) {
			passWord[index] = alphabets[i];
			if (alphabets[i] == 'a' || alphabets[i] == 'e' || alphabets[i] == 'i'|| alphabets[i] == 'o' || alphabets[i] == 'u'){
				Combi(passWord, index+1, i+1, con, vow+1);
			}
			else {
				Combi(passWord, index+1, i+1, con+1, vow);
			}
		}
	}
}
