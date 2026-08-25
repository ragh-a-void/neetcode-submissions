class Solution {
    private:
    int dfs(int i,int j, vector<vector<int>>& grid){
        if(i<0 or j<0 or i>=grid.size() or j>= grid[0].size()){
            return 0;
        }
        if(grid[i][j]!=1){
            return 0;
        }
        grid[i][j]=2;
        int ans=1;
        ans+=dfs(i,j+1,grid);
        ans+=dfs(i+1,j,grid);
        ans+=dfs(i,j-1,grid);
        ans+=dfs(i-1,j,grid);
        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;
        int n = grid.size(), m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    maxArea=max(maxArea,dfs(i,j,grid));
                }
            }
        }
        return maxArea;
    }
};
