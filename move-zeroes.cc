//https://leetcode.com/problems/move-zeroes/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    	for (int i = 0, now = 0; i < nums.size(); ++i)  {
			if (nums[i] != 0) {
				swap(nums[i], nums[now++]);
			}
		}   
    }
};
