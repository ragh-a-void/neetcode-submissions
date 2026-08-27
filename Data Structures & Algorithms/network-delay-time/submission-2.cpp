#define pii pair<int, int>
#define pb push_back

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int maxTime = 0;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push({0, k});
        
        vector<vector<pii>> adj(n+1, vector<pii>());
        for(auto& time: times){
            adj[time[0]].pb({time[1], time[2]});
        }

        unordered_set<int> visited;
        
        while(!q.empty()){
            pii curr = q.top();
            q.pop();
            int currTime = curr.first, currNode = curr.second;
            if(visited.count(currNode)){
                continue;
            }
            maxTime = max(maxTime, currTime);
            visited.insert(currNode);
            for(auto x: adj[currNode]){
                int nextNode = x.first, nextTime = x.second;
                if(!visited.count(nextNode)){
                    int totalTime = currTime + nextTime;
                    q.push({totalTime, nextNode});
                }
            }
        }

        return visited.size() == n ? maxTime : -1;
    }
};
