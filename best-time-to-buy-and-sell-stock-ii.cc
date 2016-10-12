//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int result = 0;
  		for (int i = 1; i < prices.size(); ++i) {
			result += max(0, prices[i] - prices[i-1]);
		}  
		return result;
    }
};
