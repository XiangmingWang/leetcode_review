//https://leetcode.com/problems/number-of-islands/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        m_ = grid.size();
        n_ = grid[0].size();
        int count = 0;
        for (int i = 0; i < m_; ++i) {
            for (int j = 0; j < n_; ++j) {
                if (grid[i][j] == '0') continue;
                dfs(grid, i, j);
                ++count;
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& grid,
             int i, int j) {
        if (i < 0 || i >= m_ || j < 0 || j >= n_ || grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
private:
    int m_;
    int n_;
};
