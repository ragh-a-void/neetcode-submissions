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
        vector<pair<int, pair<int, int>>> edges;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j){
                    int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                    edges.push_back({dist, {i, j}});
                }
            }
        }

        // build DSU
        DSU dsu(n);

        // sort edges based on dist
        sort(edges.begin(), edges.end());

        // join all nodes
        int ans = 0;
        for(auto& [dist, node]: edges){
            auto& [i, j] = node;
            // cout << dist << " " << i << " " << j << endl;
            if(dsu.join(i, j)){
                ans += dist;
            }
        }

        return ans;
    }
};
