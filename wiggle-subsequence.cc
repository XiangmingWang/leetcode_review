//https://leetcode.com/problems/wiggle-subsequence/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        bool now_pos; 
        int total_count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1]) continue;
            if (i == 1) {
                ++total_count;
                now_pos = nums[i] > nums[i-1];
                continue;
            }
            if (nums[i] > nums[i-1] == now_pos) continue;
            ++total_count;
            now_pos = !now_pos;
        }
        return total_count;
    }
};
