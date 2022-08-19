package BJ10845;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

	static ArrayList<Integer> queue;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		queue = new ArrayList<>();
		
		int N = Integer.parseInt(br.readLine());
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			String command = st.nextToken();

			if (command.equals("push")) {
				int x = Integer.parseInt(st.nextToken());
				push(x);
			} else if (command.equals("pop")) System.out.println(pop());
			else if (command.equals("size")) System.out.println(size());
			else if (command.equals("empty")) System.out.println(empty());
			else if (command.equals("front")) System.out.println(front());
			else if (command.equals("back")) System.out.println(back());
		}
	}

	public static void push(int x) {
		queue.add(x);
	}
	public static int pop() {
		int tmp = -1;
		if (!queue.isEmpty()) {
			tmp = queue.get(0);
			queue.remove(0);
		}
		
		return tmp;
	}
	public static int size() {
		return queue.size();
	}
	public static int empty() {
		if (queue.isEmpty()) return 1;
		else return 0;
	}
	public static int front() {
		if (!queue.isEmpty()) {
			return queue.get(0);
		}
		return -1;
	}
	public static int back() {
		if (!queue.isEmpty()) {
			return queue.get(queue.size()-1);
		}
		return -1;
	}
}
