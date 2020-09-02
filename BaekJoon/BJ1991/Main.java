package BJ1991;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static Node root = null;
	
	static class Node{
		char data;
		Node  left;
		Node right;
		
		public Node(char data) {
			this.data = data;
			left = null;
			right = null;
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		
		char[] set = br.readLine().replaceAll(" ",  "").toCharArray();
		char data = set[0];
		char left = set[1];
		char right = set[2];
		
		root = new Node(data);
		if (left != '.') root.left = new Node(left);
		if (right != '.') root.right = new Node(right);
		
		for (int i = 1; i < N; i++) {
			set = br.readLine().replaceAll(" ",  "").toCharArray();
			data = set[0];
			left = set[1];
			right = set[2];
			push(root, data, left, right);
		}
		
		preOrder(root);
		System.out.println();
		inOrder(root);
		System.out.println();
		postOrder(root);
		
	}
	
	private static void push(Node tRoot, char tData, char tLeft, char tRight) {
		if (tRoot == null) return;
		
		if (tRoot.data == tData) {
			if (tLeft != '.') tRoot.left = new Node(tLeft);
			if (tRight != '.') tRoot.right = new Node(tRight);
			return;
		} else {
			push(tRoot.left, tData, tLeft, tRight);
			push(tRoot.right, tData, tLeft, tRight);
		}
	}
	
	private static void preOrder(Node n) {
		if (n == null) return;
		
		System.out.print(n.data);
		preOrder(n.left);
		preOrder(n.right);
	}
	
	private static void postOrder(Node n) {
		if (n == null) return;
		
		postOrder(n.left);
		postOrder(n.right);
		System.out.print(n.data);
	}
	
	private static void inOrder(Node n) {
		if (n == null) return;
		
		inOrder(n.left);
		System.out.print(n.data);
		inOrder(n.right);
	}
}
