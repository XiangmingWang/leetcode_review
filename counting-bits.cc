//https://leetcode.com/problems/counting-bits/
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1, 0);
        dp[1] = 1;
        int now = 1;
        for (int i = 2; i <= num; ++i) {
            if (i - now == now) {
                dp[i] = 1;
                now = i;
            } else {
                dp[i] = dp[now] + dp[i-now];
            }
        }
        return dp;
    }
};
