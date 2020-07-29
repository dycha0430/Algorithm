package leetCode64;

public class Solution {
	static int[][] mem;
	
	public static int minPathSum(int[][] grid) {
		mem = new int[grid.length][grid[0].length];

		for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid[0].length; j++) {
				mem[i][j] = minSum(grid, i, j);
			}
		}
		
		return mem[grid.length-1][grid[0].length-1];
    }
	
	public static int minSum(int[][] grid, int i, int j) {
		if (i == 0 && j == 0) return grid[i][j];
		else if (i == 0) return grid[i][j] + mem[i][j-1];
		else if (j == 0) return grid[i][j] + mem[i-1][j];
		else return grid[i][j] + Math.min(mem[i][j-1], mem[i-1][j]);
	}
	
	public static void main(String[] args) {
		int[][] grid = {{1,4,8,6,2,2,1,7},{4,7,3,1,4,5,5,1},{8,8,2,1,1,8,0,1},{8,9,2,9,8,0,8,9},{5,7,5,7,1,8,5,5},{7,0,9,4,5,6,5,6},{4,9,9,7,9,1,9,0}};
		System.out.println(minPathSum(grid));
		for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid[0].length; j++)
				System.out.print(mem[i][j] + "(" + grid[i][j] + ")  ");
			System.out.println();
		}
	}
}