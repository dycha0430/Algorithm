package leetCode53;

public class Solution {
    public int maxSubArray(int[] nums) {
    	int maxSum = nums[0], curSum = 0;
        for (int i = 0; i < nums.length; i++) {
        	curSum += nums[i];
        	if (maxSum < curSum) maxSum = curSum;
        	if (curSum < 0) curSum = 0;
        }
        
        return maxSum;
    }
}
