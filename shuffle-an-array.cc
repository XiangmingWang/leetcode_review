//https://leetcode.com/problems/shuffle-an-array/
class Solution {
private:
    vector<int> nums_;
public:
    Solution(vector<int> nums) {
        nums_ = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums_;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> tmp(nums_);
        for (int i = 0; i < tmp.size(); ++i) {
            int pos = rand() % (tmp.size() - i);
            swap(tmp[i+pos], tmp[i]);
        }
        return tmp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
