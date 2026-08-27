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

    int bfs(string& beginWord, string& endWord, unordered_map<string, unordered_set<string>>& adj){
        int ans = 1;
        queue<string> q;
        q.push(beginWord);
        set<string> visited;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                string curr = q.front();
                q.pop();
                if(curr == endWord){
                    return ans;
                }
                for(int i = 0; i < curr.size(); i++){
                    string pattern = curr.substr(0, i) + "*" + curr.substr(i+1);
                    for(auto neigh: adj[pattern]){
                        if(visited.find(neigh) == visited.end()){
                            q.push(neigh);
                            visited.insert(neigh);
                        }
                    }
                }
            }
            ans++;
        }
        return 0;
    }

    void addNeigh(string& word, unordered_map<string, unordered_set<string>>& adj){
        for(int i = 0; i < word.size(); i++){
            string pattern = word.substr(0, i) + "*" + word.substr(i+1);
            adj[pattern].insert(word);
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
            addNeigh(word, adj);
        }
        addNeigh(beginWord, adj);
        addNeigh(endWord, adj);

        for(auto x: adj){
            cout << x.first << ": ";
            for(auto y: x.second){
                cout << y << " ";
            }
            cout << endl;
        }
        return bfs(beginWord, endWord, adj);
    }
};
