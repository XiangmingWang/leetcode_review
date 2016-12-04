//https://leetcode.com/problems/longest-increasing-subsequence/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int max_dp = 1;
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if ((nums[j] < nums[i]) && (dp[j] + 1 > dp[i])) {
                    dp[i] = dp[j] + 1;
                    max_dp = max(dp[i], max_dp);
                }
            }
        }
        return max_dp;
    }
};

