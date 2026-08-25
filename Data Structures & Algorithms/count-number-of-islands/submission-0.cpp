class Solution {
private:
    void dfs(int i,int j, vector<vector<char>>& grid){
        if(i<0 or j<0 or i>=grid.size() or j>= grid[0].size()){
            return;
        }
        if(grid[i][j]!='1'){
            return;
        }
        grid[i][j]='2';
        dfs(i,j+1,grid);
        dfs(i+1,j,grid);
        dfs(i,j-1,grid);
        dfs(i-1,j,grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int totalIslands=0;
        int n = grid.size(), m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    totalIslands++;
                    dfs(i,j,grid);
                }
            }
        }
        return totalIslands;
    }
};