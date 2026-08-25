class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        for(auto x: prerequisites){
            adj[x[1]].push_back(x[0]);
        }
        vector<int> inOrder(numCourses, 0);
        for(auto x: adj){
            for(auto neigh: x){
                inOrder[neigh]++;
            }
        }
        vector<int> validOrder;
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(inOrder[i] == 0){
                q.push(i);
                validOrder.push_back(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto x: adj[curr]){
                inOrder[x]--;
                if(inOrder[x] == 0){
                    q.push(x);
                    validOrder.push_back(x);
                }
            }
        }
        for(auto x: inOrder){
            if(x > 0){
                vector<int> inValidOrder;
                return inValidOrder;
            }
        }
        return validOrder;
    }
};
