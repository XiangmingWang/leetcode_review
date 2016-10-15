//https://leetcode.com/problems/game-of-life/
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty()) return;
        int m = board.size(), n = board[0].size();
        int dx[] = {-1, -1, -1,  1, 1, 1,  0, 0};
        int dy[] = {-1,  0,  1, -1, 0, 1, -1, 1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int live_count = 0;
                for (int k = 0; k < 8; ++k) {
                    if (i+dx[k]<m &&
                        i+dx[k]>=0 &&
                        j+dy[k]<n &&
                        j+dy[k]>=0 &&
                        (board[i+dx[k]][j+dy[k]] == 1 ||
                        board[i+dx[k]][j+dy[k]] == 2))
                        ++live_count;
                }
                if (live_count < 2 && (board[i][j] == 1 || board[i][j] == 2)) board[i][j] = 2;
                else if ((live_count == 2 || live_count == 3) &&
                        (board[i][j] == 1 || board[i][j] == 2)) board[i][j] = 1;
                else if (live_count > 3 &&
                        (board[i][j] == 1 || board[i][j] == 2)) board[i][j] = 2;
                else if (live_count == 3 &&
                        (board[i][j] == 0 || board[i][j] == 3)) board[i][j] = 3;
                else {
                    if (board[i][j] == 1 || board[i][j] == 2) board[i][j] = 1;
                    else board[i][j] = 0;
                }
            }
            
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] %= 2;
            }
        }
    }
};
