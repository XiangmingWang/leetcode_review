//https://leetcode.com/problems/n-queens-ii/
#include "leetcode.h"
class Solution {
public:
    int totalNlQueens(int n) {
        int result = 0;
        vector<string> tmp(n, string(n, '.'));
        dfs(result, tmp, 0, n);
        return result;    
    }
    void dfs(int& result, vector<string>& tmp, int row, const int n) {
        if (row == n) {
            ++result;
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (!Check(tmp, col, row, n)) continue;
            tmp[row][col] = 'Q';
            dfs(result, tmp, row+1, n);
            tmp[row][col] = '.';
        }
    }
    bool Check(vector<string>& tmp, int col, int row, int n) {
        for (int i = 0; i <= row; ++i) {
            if (tmp[i][col] == 'Q') return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (tmp[i][j] == 'Q') return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (tmp[i][j] == 'Q') return false;
        }
        return true;
    }
};
int main() {

}
