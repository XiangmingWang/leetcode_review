//https://leetcode.com/problems/surrounded-regions/
class Solution {
queue<pair<int, int>> q;
void bfs(vector<vector<char>>& board, int i, int j){
    if(board[i][j] != 'O') return;
    board[i][j] = 'B';
    
    q.push(make_pair(i, j));
    
    int m = board.size();
    int n = board[0].size();
    while (!q.empty()){
        auto next = q.front();
        q.pop();
        int i = next.first, j = next.second;
        board[i][j] = 'B';
        if (i > 0 && board[i - 1][j] == 'O'){
            board[i - 1][j] = 'B';
            q.push(make_pair(i - 1, j));
        }
        if (i<m - 1 && board[i + 1][j] == 'O'){
            board[i+1][j] = 'B';
            q.push(make_pair(i + 1, j));
        }
        if (j>0 && board[i][j - 1] == 'O'){
            board[i][j-1] = 'B';
            q.push(make_pair(i, j - 1));
        }
        if (j < n - 1 && board[i][j + 1] == 'O'){
            board[i][j+1] = 'B';
            q.push(make_pair(i, j + 1));
        }
    }
}
void change(vector<vector<char>>& board){
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if ('O' == board[i][j]) board[i][j] = 'X';
            else if ('B' == board[i][j]) board[i][j] = 'O';
        }
    }
}
public:
void solve(vector<vector<char>>& board) {
    if (board.empty())  return;
    int m = board.size();
    int n = board[0].size();
    
    for (int i = 0; i < m; i++){
        if (board[i][0] == 'O') bfs(board, i, 0);
        if (board[i][n - 1] == 'O') bfs(board, i, n - 1);
    }
    for (int i = 0; i < n - 1; i++){
        if (board[0][i] == 'O') bfs(board, 0, i);
        if (board[m - 1][i] == 'O') bfs(board, m - 1, i);
    }

    change(board);
}
};
