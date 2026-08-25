class Solution {
private:
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    bool isValid(int x, int y, vector<vector<int>>& arr, vector<vector<bool>>& visited){
        if(x < 0 or y < 0){
            return false;
        }
        if(x >= arr.size() or y >= arr[0].size()){
            return false;
        }
        return !visited[x][y];
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        if(image[sr][sc] == color){
            return image;
        }
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        visited[sr][sc] = true;
        while(!q.empty()){
            pair<int, int> curr = q.front();
            q.pop();
            int currX = curr.first, currY = curr.second;
            int currColor = image[currX][currY];
            image[currX][currY] = color;
            for(int i = 0; i < 4; i++){
                int newX = currX + dx[i], newY = currY + dy[i];
                if(isValid(newX, newY, image, visited) and image[newX][newY] == currColor){
                    q.push({newX, newY});
                    visited[newX][newY] = true;
                }
            }
        }
        return image;
    }
};