class Solution {
private:
    int findParent(int node, vector<int>& par){
        while(node != par[node]){
            int parent = par[node];
            int skipParent = par[parent];
            par[node] = skipParent;
            node = par[node];
        }
        return node;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> par(n+1);
        vector<int> size(n+1, 1);
        for(int i = 1; i <= n; i++){
            par[i] = i;
        }
        for(auto edge: edges){
            int parA = findParent(edge[0], par);
            int parB = findParent(edge[1], par);
            if(parA == parB){
                return edge;
            }
            if(size[parA] > size[parB]){
                size[parA] += size[parB];
                par[parB] = parA;
            }else{
                size[parB] += size[parA];
                par[parA] = parB;
            }
        }
    }
};
