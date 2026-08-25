class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        queue<pair<pair<int, int>, int>> q;
        int freshCount = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                }else if(grid[i][j] == 1){
                    freshCount++;
                }
            }
        }

        int maxTime = 0;

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int currX = curr.first.first;
            int currY = curr.first.second;
            int time = curr.second;
            maxTime = max(maxTime, time);
            for(int i = 0; i < 4; i++){
                int newX = currX + dx[i];
                int newY = currY + dy[i];
                if(newX >= 0 and newY >= 0 and newX < n and newY < m and grid[newX][newY] == 1){
                    q.push({{newX, newY}, time+1});
                    grid[newX][newY] = 2;
                    freshCount--;
                }
            }
        }

        return freshCount == 0 ? maxTime : -1;
    }
};
