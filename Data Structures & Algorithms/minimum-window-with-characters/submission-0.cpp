#define um unordered_map
class Solution {
private:
    bool isPresent(um<char, int>& freqS, um<char, int>& freqT){
        for(auto [c, count]: freqT){
            if(count > freqS[c]){
                return false;
            }
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        int nS = s.size(), nT = t.size();
        um<char, int> freqS, freqT;
        for(char c: t){
            freqT[c]++;
        }
        int start = 0, end = 0, ansStart = -1, minLen = INT_MAX;

        while(end < nS){
            while(end < nS and !isPresent(freqS, freqT)){
                freqS[s[end++]]++;
            }
            while(start <= end and isPresent(freqS, freqT)){
                int currLen = end - start;
                if(currLen < minLen){
                    ansStart = start;
                    minLen = currLen;
                }
                freqS[s[start++]]--;
            }
        }
        return ansStart == -1 ? "" : s.substr(ansStart, minLen);
    }
};
