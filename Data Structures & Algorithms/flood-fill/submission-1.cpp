class Solution {
private:
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    bool isValid(int x, int y, vector<vector<int>>& arr){
        if(x < 0 or y < 0){
            return false;
        }
        if(x >= arr.size() or y >= arr[0].size()){
            return false;
        }
        return true;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        int currColor = image[sr][sc];
        if(currColor == color){
            return image;
        }
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        while(!q.empty()){
            pair<int, int> curr = q.front();
            q.pop();
            int currX = curr.first, currY = curr.second;
            for(int i = 0; i < 4; i++){
                int newX = currX + dx[i], newY = currY + dy[i];
                if(isValid(newX, newY, image) and image[newX][newY] == currColor){

                    image[newX][newY] = color;
                    q.push({newX, newY});
                }
            }
        }
        return image;
    }
};