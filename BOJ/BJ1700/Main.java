package BJ1700;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.StringTokenizer;

public class Main {
	static int N, K, min;
	static int[] product;
	static ArrayList<Integer> multitap;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		st = new StringTokenizer(br.readLine(), " ");
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		min = K;
		
		multitap = new ArrayList<>();
		product = new int[K];
		
		st = new StringTokenizer(br.readLine(), " ");
		for (int i = 0; i < K; i++) {
			product[i] = Integer.parseInt(st.nextToken());
		}
		
		plug(0, 0);
		
		System.out.println(min);
		
	}
	
	private static void plug(int k, int num) {
		if (k == K) {
			min = Math.min(num, min);
			return;
		} else if (multitap.contains(product[k])) {
			plug(k+1, num);
			return;
		} else if (multitap.size() < N) {
			multitap.add(product[k]);
			plug(k+1, num);
			return;
		} else {
			Iterator<Integer> iter = multitap.iterator();
			int maxIndex = 0;
			while(iter.hasNext()) {
				int i = iter.next();
				int index = -1;
				
				for (int j = k; j < K; j++) {
					if (i == product[j]) {
						index = j;
						break;
					}
				}
				
				if (index == -1) {
					multitap.remove(multitap.indexOf(i));
					multitap.add(product[k]);
					plug(k+1, num+1);
					return;
				}
				maxIndex = Math.max(maxIndex, index);
			}
			multitap.remove(multitap.indexOf(product[maxIndex]));
			multitap.add(product[k]);
			plug(k+1, num+1);
			return;
			
		}
	}
}