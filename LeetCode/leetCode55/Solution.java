package leetCode55;

class Solution {
    int[] memo;
    
    public boolean canJump(int[] nums) {
        memo = new int[30000];
        return oneJump(nums, 0);
    }
    
    private boolean oneJump(int[] nums, int index) {
    	if (index >= nums.length-1) {
    		return true;
    	}
        
        if (memo[index] == 1) return false;
        
    	for (int i = nums[index]; i > 0; i--) {
    		if (oneJump(nums, index+i) == true) {
    			return true;
    		}
    	}
        memo[index] = 1;
    	return false;
    }
}