//https://leetcode.com/problems/largest-divisible-subset/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> result;
        vector<int> parent(nums.size(), 0);
        vector<int> T(nums.size(), 0);
        int m = 0, mi = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            for (int j = i; j < nums.size(); ++j) {
                if ((nums[j] % nums[i] == 0) && (T[j] + 1 > T[i])) {
                    T[i] = T[j] + 1;
                    parent[i] = j;
                    if (T[i] > m) {
                        m = T[i];
                        mi = i;
                    }
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            result.push_back(nums[mi]);
            mi = parent[mi];
        }
        return result;
    }
};
