package Problem1;

import java.util.Scanner;

class Solution {
	static int Answer;
	static int[] mem;
	static int[] sum;
	public static void main(String args[]) throws Exception	{
		Scanner sc = new Scanner(System.in);
	
		double h = 3, R = 10;
		double a = Math.acos(1-h/R)*R*2;
		double b = Math.PI*R - 2*R*Math.asin(1-h/R);
		System.out.println(a +" ," + b);
		System.out.println(Math.asin(1-h/R) + Math.acos(1-h/R));
		
		mem = new int[1000001];
		sum = new int[1000001];
		int T = sc.nextInt();
		
		//�κ����� ������ ���ؾ� �ϴ� ��� prefix Sum�� �̸� ��� ���س��� ���� �� ����.
		for (int i = 1; i <= 1000000; i++) {
			sum[i] += sum[i-1] + work(i);
		}
		
		//for�� ������ for���� �� ���� ���ϸ� �ð��ʰ�
		for(int test_case = 0; test_case < T; test_case++) {
			int N1 = sc.nextInt();
			int N2 = sc.nextInt();
			
			System.out.println("Case #"+(test_case+1));
			System.out.println(sum[N2] - sum[N1-1]);
		}
	}
	
	public static int work(int num) {
		if (mem[num] != 0 || num == 1) return mem[num];
		else if (num%2 == 0) return mem[num] = work(num/2) + 1;
		else return mem[num] = work(num+1) + 1;
	}
}
