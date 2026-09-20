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

        int ans = 0, l = 0, r = 0;
        um<char, int> freq;
        int maxF = 0;

        while(r < n){
            // while(r < n and maxF + k >= r - l + 1){
            //     cout << l << " | " << r << " | " << maxF << endl;
            //     freq[s[r++]]++;
            //     maxF = maxFreq(freq);
            // }
            freq[s[r]]++;
            while(l <= r and maxFreq(freq) + k < r - l + 1){
                cout << l << " * " << r << " | " << maxFreq(freq) << endl;
                freq[s[l++]]--;
                // maxF = maxFreq(freq);
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
