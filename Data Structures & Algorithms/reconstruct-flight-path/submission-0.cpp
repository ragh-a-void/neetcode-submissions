class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, queue<string>> adj;
        sort(tickets.begin(), tickets.end());
        for (auto& ticket : tickets) {
            adj[ticket[0]].push(ticket[1]);
        }
        // for (auto& [src, dests] : adj) {
        //     sort(dests.begin(), dests.end());
        //     cout << src << ": ";
        //     for(auto x: dests) cout << x << " ";
        //     cout << endl;
        // }
        vector<string> res;
        dfs("JFK", adj, res);
        reverse(res.begin(), res.end());
        return res;
    }

private:
    void dfs(const string& src, unordered_map<string,
             queue<string>>& adj, vector<string>& res) {
        while (!adj[src].empty()) {
            string dst = adj[src].front();
            adj[src].pop();
            dfs(dst, adj, res);
        }
        res.push_back(src);
    }
};