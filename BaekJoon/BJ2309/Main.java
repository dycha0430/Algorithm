package BJ2309;

import java.util.Arrays;
import java.util.Scanner;

public class Main {
	static int[] heights;
	static int sum = 0;
	static int[] notDwarf;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		notDwarf = new int[2];
		heights = new int[9];
		for (int i = 0; i < 9; i++) {
			heights[i] = sc.nextInt();
			sum += heights[i];
		}
		
		Arrays.sort(heights);
		
		findDwarf(0, sum, 0);
	}
	
	private static void findDwarf(int start, int curSum, int num) {
		if (num == 2) {
			if (curSum == 100) {
				for (int i = 0; i < 9; i++) {
					if (heights[i] != notDwarf[0] && heights[i] != notDwarf[1])
						System.out.println(heights[i]);
				}
				System.exit(0);
			}
			return;
		}
		
		for (int i = start; i < 9; i++) {
			notDwarf[num] = heights[i];
			findDwarf(i+1, curSum-heights[i], num+1);
		}
	}
}
