//https://leetcode.com/problems/range-sum-query-2d-immutable/
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) : dp_(matrix) {
        if (dp_.empty()) return;
        for (int i = 0; i < dp_.size(); ++i) {
            for (int j = 0; j < dp_[0].size(); ++j) {
                dp_[i][j] += (i >= 1 ? dp_[i-1][j] : 0)
                          +  (j >= 1 ? dp_[i][j-1] : 0)
                          -  ((i >= 1 && j >= 1) ? dp_[i-1][j-1] : 0);
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp_[row2][col2]
               - (col1 >= 1 ? dp_[row2][col1-1] : 0)
               - (row1 >= 1 ? dp_[row1-1][col2] : 0)
               + ((row1 >= 1 && col1 >= 1) ? dp_[row1-1][col1-1] : 0);
    }
private:
    vector<vector<int>> dp_;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
