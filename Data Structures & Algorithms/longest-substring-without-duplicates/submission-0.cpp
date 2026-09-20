class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> freq;
        int start = 0, end = 0, maxLen = 0;
        while(end < n){
            while(start <= end and freq[s[end]] > 0){
                freq[s[start++]]--;
            }
            maxLen = max(maxLen, end - start + 1);
            freq[s[end++]]++;
        }
        return maxLen;
    }
};
