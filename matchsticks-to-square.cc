#include "leetcode.h"
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) return false;
        int sum = 0, a = 0;
        for (auto i : nums) {
            sum += i;
        }    
        if (sum % 4 != 0) return false;
        a = sum / 4;
        cout << "a:"<<a<<endl;
        sort(nums.begin(), nums.end());
        vector<int> edges(4, 0);
        return dfs(nums, edges,  a, 0);
    }
    bool dfs(const vector<int>& nums, vector<int>& edges, int a, int index) {
        if (index == nums.size()) {
            return true;
        }
        int curr = nums[index];
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i] + curr <= a) {
                if (i > 0 && edges[i] == edges[i-1]) {
                    continue;
                }
                edges[i] += curr;
                if (dfs(nums, edges, a, index+1)) {
                    return true;
                }
                edges[i] -= curr;
            }
        }
        return false;
    }
};
int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(10);
    nums.push_back(5);
    nums.push_back(5);
    nums.push_back(5);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(6);
    cout <<s.makesquare(nums) <<endl;
}
