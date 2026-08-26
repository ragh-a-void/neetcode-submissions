class Solution {
private:
    bool oneOff(string& a, string& b){
        int n = a.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(a[i] != b[i]){
                cnt++;
            }
            if(cnt > 1){
                return false;
            }
        }
        return cnt == 1;
    }

    void bfs(string& a, unordered_map<string, unordered_set<string>>& adj, unordered_map<string, int>& dist){
        dist[a] = 0;
        queue<string> q;
        q.push(a);
        while(!q.empty()){
            string curr = q.front();
            q.pop();
            for(auto neigh: adj[curr]){
                if(dist.find(neigh) == dist.end()){
                    q.push(neigh);
                    dist[neigh] = dist[curr] + 1;
                }
            }
        }
    }

    void addNeigh(string& word, vector<string>& wordList, unordered_map<string, unordered_set<string>>& adj){
        for(auto neigh: wordList){
                if(oneOff(word, neigh)){
                    if(adj.find(word) == adj.end()){
                        adj[word] = unordered_set<string>();
                    }
                    if(adj.find(neigh) == adj.end()){
                        adj[neigh] = unordered_set<string>();
                    }
                    adj[word].insert(neigh);
                    adj[neigh].insert(word);
                }
            }
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, unordered_set<string>> adj;
        bool isPresent = false;
        for(auto word: wordList){
            if(word == endWord){
                isPresent = true;
                break;
            }
        }
        if(!isPresent or beginWord == endWord){
            return 0;
        }

        for(auto word: wordList){
            addNeigh(word, wordList, adj);
        }
        addNeigh(beginWord, wordList, adj);
        addNeigh(endWord, wordList, adj);

        for(auto x: adj){
            cout << x.first << ": ";
            for(auto y: x.second){
                cout << y << " ";
            }
            cout << endl;
        }
        unordered_map<string, int> dist;
        bfs(beginWord, adj, dist);
        return dist.find(endWord) == dist.end() ? 0 : dist[endWord]+1;
    }
};
