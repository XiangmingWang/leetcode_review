//https://leetcode.com/problems/set-matrix-zeroes/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    	if (matrix.empty()) return;
		int m = matrix.size(), n = matrix[0].size();
		bool row_zero = false, col_zero = false;
		for (int i = 0; i < m; ++i) {
			if (matrix[i][0] == 0) {
				col_zero = true;
				break;
			}
		}   
		for (int j = 0; j < n; ++j) {
			if (matrix[0][j] == 0) {
				row_zero = true;
				break;
			}
		}   
		for (int i = 1; i < m; ++i){
			for (int j = 1; j < n; ++j) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}
		for (int i = 1; i < m; ++i) if (matrix[i][0] == 0) for (int j = 1; j < n; ++j) matrix[i][j] = 0;
		for (int j = 1; j < n; ++j) if (matrix[0][j] == 0) for (int i = 1; i < m; ++i) matrix[i][j] = 0;
		if (row_zero) for (int j = 0; j < n; ++j) matrix[0][j] = 0;
		if (col_zero) for (int i = 0; i < m; ++i) matrix[i][0] = 0;
    }
};
