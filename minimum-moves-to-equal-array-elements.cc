//https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = INT_MAX;  
        int sum = 0;  
        for(const int& n : nums){  
            mini = min(mini, n);  
            sum += n;  
        }  
        return sum - nums.size() * mini;  
    }
};
