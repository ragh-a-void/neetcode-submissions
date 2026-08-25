class Solution {
private:
    vector<pair<int, int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    void dfs(int x, int y, vector<vector<bool>>& visited, vector<vector<int>>& heights){
        visited[x][y] = true;
        for(auto [dx, dy]: dir){
            int newX = x + dx, newY = y + dy;
            if(newX >= 0 and newY >= 0 and newX < heights.size() and newY < heights[0].size() and !visited[newX][newY] and heights[x][y] <= heights[newX][newY]){
                dfs(newX, newY, visited, heights);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++){
            dfs(i, 0, pac, heights);
            dfs(i, m-1, atl, heights);
        }
        for(int i = 0; i < m; i++){
            dfs(0, i, pac, heights);
            dfs(n-1, i, atl, heights);
        }
        vector<vector<int>> validHeights;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(pac[i][j] and atl[i][j]){
                    validHeights.push_back({i, j});
                }
            }
        }
        return validHeights;
    }
};
