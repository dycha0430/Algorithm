package BJ1946;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

class Pair
{
       private int key;
       private int value;

       public Pair(int aKey, int aValue)
       {
           key   = aKey;
           value = aValue;
       }

       public int key()   { return key; }
       public int value() { return value; }
}

public class Main {

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		Comparator<Pair> pairComparator = new Comparator<Pair>() {
			@Override
			public int compare(Pair o1, Pair o2) {
				return o1.key() - o2.key();
			}		
		};
		
		int T = Integer.parseInt(br.readLine());
		for (int test_case = 0; test_case < T; test_case++) {
			int N = Integer.parseInt(br.readLine());
			ArrayList<Pair> emps = new ArrayList<>();
			
			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine(), " ");
				emps.add(new Pair(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
			}
			
			Collections.sort(emps, pairComparator);
			
			int Answer = N;
			int[] nonPass = new int[N];
			for (int i = 0; i < N; i++) {
				for (int j = i-1; j >= 0; j--) {
					if (emps.get(i).value() > emps.get(j).value()) {
						--Answer;
						nonPass[i] = 1;
						break;
					} else if (nonPass[j] == 0) {
						break;
					}
				}
			}
			
			System.out.println(Answer);
		}
	}
}
