//https://leetcode.com/problems/combination-sum-iv/
class Solution {
public:
dfs: TLE
    int combinationSum4(vector<int>& nums, int target) {
        int sum = 0;
        sort(nums.begin(), nums.end());
        dfs(nums, target, sum);    
        return sum;
    }
    void dfs(vector<int>& nums, int target, int& sum) {
        int new_target;
        for (int i = 0; i < nums.size(); ++i) {
            new_target = target - nums[i];
            if (new_target < 0) break;
            if (new_target == 0) {
                ++sum;
                break;
            }
            dfs(nums, new_target, sum);
        }
    }

dp: AC
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int x : nums) {
                if (i - x < 0) continue;
                dp[i] += dp[i - x];
            }
        }
        return dp[target];
    }
    
};

