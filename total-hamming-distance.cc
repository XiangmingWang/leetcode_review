#include "leetcode.h"
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        if (nums.size() <= 1) return 0; 
        int ret = 0;
        int len = nums.size(); 
        vector<int> m(32, 0);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0 ; j < 32; ++j) {
                m[j] += (nums[i]>>j&1); 
            }
        }
        for (int j = 0; j < 32; ++j) {
            ret += m[j] * (len - m[j]);
        }
        return ret;
    }
};
int main() {
    vector<int> nums;
    Solution s;
    nums.push_back(4);
    nums.push_back(14);
    nums.push_back(2);
    cout << s.totalHammingDistance(nums) << endl;
}
