class DSU {
    private:
        vector<int> par, sz;
        int findPar(int x){
            while(par[x] != x){
                par[x] = par[par[x]];
                x = par[x];
            }
            return x;
        }
    public:
        DSU(int n): par(n+1), sz(n+1, 1) {
            for(int i = 0; i <= n; i++){
                par[i] = i;
            }
        }
        bool join(int x, int y){
            int parX = findPar(x), parY = findPar(y);
            if(parX == parY){
                return false;
            }
            if(sz[parX] > sz[parY]){
                par[parY] = parX;
            }else{
                par[parX] = parY;
            }
            return true;
        }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        // build adj
        vector<vector<pair<int, int>>> adj(n, vector<pair<int,int>>());
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j){
                    int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                    adj[i].push_back({j, dist});
                }
            }
        }

        unordered_set<int> visited;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        minHeap.push({0, 0});

        // while all nodes are not visited
        int ans = 0;

        while(visited.size() < n){
            auto [dist, currNode] = minHeap.top();
            minHeap.pop();
            if(visited.count(currNode)){
                continue;
            }
            visited.insert(currNode);
            ans += dist;
            for(auto& [nextNode, dist]: adj[currNode]){
                if(!visited.count(nextNode)){
                    minHeap.push({dist, nextNode});
                }
            }
        }
        

        return ans;
    }
};
