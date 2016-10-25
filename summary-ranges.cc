//https://leetcode.com/problems/summary-ranges/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.empty()) return result;
      stringstream ss;
        int left = nums[0], right = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i-1] + 1) {
            ss.str("");
                if (left == right) ss << left;
                else ss << left << "->" << right;
                result.push_back(ss.str());
                left = nums[i];
                right = nums[i];
            } else {
                right = nums[i];
            }
        }
      ss.str("");
        if (left == right) ss << left;
        else ss << left << "->" << right;
        result.push_back(ss.str());
        return result;
    }
};
int main() {
   Solution s;
   vector<int> nums;
   nums.push_back(-1);
   s.summaryRanges(nums);
}
