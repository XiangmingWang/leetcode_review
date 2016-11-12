//https://leetcode.com/problems/house-robber/
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.begin(), nums.end());
        if (dp[1] < dp[0]) dp[1] = dp[0];
        for (size_t i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp.back();
    }
};
