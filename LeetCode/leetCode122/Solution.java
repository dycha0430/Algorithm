package leetCode122;

public class Solution {
	public static int maxProfit(int[] prices) {
		int buy = 0, sell = -1, output = 0;
		while (true) {
			buy = sell+1;
			while (buy < prices.length-1 && prices[buy] > prices[buy+1]) buy++;
			if (buy >= prices.length-1) break;
	        
	        sell = buy+1;
	        while (sell < prices.length-1 && prices[sell] < prices[sell+1]) sell++;
	        if (sell > prices.length-1) break;
	        if (sell == prices.length-1 && prices[buy] >= prices[sell]) break;
	        output += prices[sell] - prices[buy];
		}
		
		return output;
    }
}