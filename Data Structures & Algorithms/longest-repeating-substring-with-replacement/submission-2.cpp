#define um unordered_map
class Solution {
private:
    int maxFreq(um<char, int>& freq){
        int maxF = 0;
        for(auto [c, count]: freq){
            maxF = max(maxF, count);
        }
        return maxF;
    }
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_set<char> charSet(s.begin(), s.end());

        um<char, int> freq;
        int ans = 0, l = 0, r = 0;
        int maxF = 0;

        while(r < n){
            freq[s[r]]++;
            while(l <= r and maxFreq(freq) + k < r - l + 1){
                freq[s[l++]]--;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        
        if(maxF + k >= r - l){
            ans = max(ans, r - l);
        }
        return ans;
    }
};


/*

brute force:
    for each character, note it's positions in string
    



*/
