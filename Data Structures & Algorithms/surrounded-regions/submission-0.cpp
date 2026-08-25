class Solution {
private:
    vector<pair<int, int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    void dfs(int x, int y, vector<vector<char>>& board){
        board[x][y] = '!';
        for(auto [dx, dy]: dir){
            int newX = x + dx, newY = y + dy;
            if(newX >= 0 and newY >= 0 and newX < board.size() and newY < board[0].size() and board[newX][newY] == 'O'){
                dfs(newX, newY, board);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> atl(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O'){
                dfs(i, 0, board);
            }
            if(board[i][m-1] == 'O'){
                dfs(i, m-1, board);
            }
        }
        for(int i = 0; i < m; i++){
            if(board[0][i] == 'O') dfs(0, i, board);
            if(board[n-1][i] == 'O') dfs(n-1, i, board);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                board[i][j] = (board[i][j] == '!') ? 'O' : 'X';
            }
        }
    }
};
