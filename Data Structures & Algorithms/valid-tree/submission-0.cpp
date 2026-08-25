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
    bool validTree(int n, vector<vector<int>>& edges) {
        // if N nodes, N-1 edges should be there
        // all N nodes should be connected to each other, hence 1 connected componenet
        int m = edges.size();
        if(m != n-1){
            return false;
        }
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
        return connectedComp == 1;
    }
};
