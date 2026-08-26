class Solution {
private:
    void dfs(int curr, vector<bool>& visited, vector<vector<int>>& adj){
        visited[curr] = true;
        for(auto x: adj[curr]){
            if(!visited[x]){
                dfs(x, visited, adj);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        
        vector<vector<int>> adj(n, vector<int>());
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int connectedComp = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                connectedComp++;
                dfs(i, visited, adj);
            }
        }
        return connectedComp;
    }
};