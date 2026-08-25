class Solution {
private:
    void bfs(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0){
                    visited[i][j] = true;
                    q.push({{i, j}, 0});
                }
            }
        }
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int currX = curr.first.first;
            int currY = curr.first.second;
            int dist = curr.second;
            for(int i = 0; i < 4; i++){
                int newX = currX + dx[i];
                int newY = currY + dy[i];
                if(newX >= 0 and newY >= 0 and newX < n and newY < m and !visited[newX][newY] and grid[newX][newY] != -1){
                    visited[newX][newY] = true;
                    q.push({{newX, newY}, dist+1});
                    grid[newX][newY] = dist+1;
                }
            }
        }
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        bfs(grid);
    }
};
