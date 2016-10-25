//https://leetcode.com/problems/random-pick-index/
class Solution {
public:
    Solution(vector<int> nums) {
        nums_ = nums;
    }

    int pick(int target) {
        
        int picked = -1;
        size_t counter = 0;
        for (size_t i = 0; i < nums_.size(); ++i) {
            if (nums_[i] != target) continue;
            ++counter;
            if (rand() % counter == 0) picked = i;
        }
        return picked;
    }

private:
    vector<int> nums_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
