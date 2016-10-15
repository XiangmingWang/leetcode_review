//https://leetcode.com/problems/product-of-array-except-self/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
		int len = nums.size();
		vector<int> result(len, 1);
    	vector<int> v1(len, 1);    
    	vector<int> v2(len, 1);    
		for (int i = 0; i < len - 1; ++i) {
			v1[i+1] = v1[i] * nums[i];
		}
		for (int i = len - 1; i > 0; --i) {
			v2[i-1] = v2[i] * nums[i];
		}
		for (int i = 0; i < len; ++i) {
			result[i] = v1[i] * v2[i];
		}
		return result;
    }
};
