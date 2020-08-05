package leetCode33;

import java.util.Scanner;

public class Solution {
	public static int search(int[] nums, int target) {
		if (nums.length == 0) return -1;
		int big = nums.length - 1, find = -1;
		if (target >= nums[0]) big = 0;
        int start = 0, end = nums.length-1;
        int mid = (start + end) / 2;
        
    	while (true) {
			mid = (start + end) / 2;
    		if (mid  == 0 || mid == nums.length-1 || nums[mid] > nums[mid+1]) break;
   			else if (nums[mid] < nums[0]) {
   				end = mid;
    		} else {
   				start = mid + 1;
    		}
    	}
        
    	if (big == 0) {
    		start = 0;
    		end = mid + 1;
    	} else if (big == nums.length - 1) {
    		start = mid + 1;
    		end = nums.length;
    	}
    	
    	while (start <= end) {
    		if (start > nums.length - 1) break;
    		mid = (start + end) / 2;
    		if (nums[mid] == target) {
    			return mid;
    		} else if (nums[mid] > target) {
    			end = mid - 1;
    		} else {
    			start = mid + 1;
    		}
    	}
    	
    	return -1;
    }
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] nums = new int[7];
		for (int i = 0; i < 7; i++) {
			nums[i] = sc.nextInt();
		}
		
		System.out.println(search(nums, 3));
	}
}