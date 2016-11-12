//https://leetcode.com/problems/range-sum-query-immutable/
class NumArray {
public:
    NumArray(vector<int> &nums) : acc_(nums.begin(), nums.end()){
        for (size_t i = 1; i < acc_.size(); ++i) {
            acc_[i] += acc[i-1];
        }
    }

    int sumRange(int i, int j) {
        if (i == 0) return acc_[j];
        return acc_[j] - acc_[i-1];    
    }
private:
    vector<int> acc_;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
