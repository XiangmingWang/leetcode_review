//https://leetcode.com/problems/coin-change/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int MAX = amount + 1;
        vector<int> dp(MAX, MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coin.size(); ++j) {
                if (coin[j] > i) continue;
                dp[i] = min(dp[i], dp[i - coin[j]] + 1);
            }
        }
        return dp[amount] < MAX ? dp[amount] : -1;
    }
};
