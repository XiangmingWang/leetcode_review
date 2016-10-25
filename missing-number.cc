//https://leetcode.com/problems/missing-number/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total_should = (0 + nums.size()) * (nums.size() + 1) / 2;
      int total_now = 0;
      for (int i = 0; i < nums.size(); ++i) {
         total_now += nums[i];
      }
      return total_should - total_now;
    }
};
