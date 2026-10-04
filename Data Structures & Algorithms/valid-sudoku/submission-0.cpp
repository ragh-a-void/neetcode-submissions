class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check duplicates in row
        for(int i = 0; i < 9; i++){
            vector<bool> visited(9, false);
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0';
                    if(visited[num]){
                        return false;
                    }
                    visited[num] = true;
                }
            }
        }
        
        // check duplicates in col
        for(int j = 0; j < 9; j++){
            vector<bool> visited(9, false);
            for(int i = 0; i < 9; i++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0';
                    if(visited[num]){
                        return false;
                    }
                    visited[num] = true;
                }
            }
        }

        // check duplicates in small square
        map<pair<int, int>, set<int>> visited;
        for(int j = 0; j < 9; j++){
            for(int i = 0; i < 9; i++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0';
                    // set<int> curr = visited[{i/3, j/3}];
                    if(visited[{i/3, j/3}].find(num) != visited[{i/3, j/3}].end()){
                        return false;
                    }
                    visited[{i/3, j/3}].insert(num);
                }
            }
        }

        return true;
    }
};
