class Solution {
private:
    bool isSame(unordered_map<char, int>& freq1, unordered_map<char, int>& freq2){
        for(auto [c, count]: freq2){
            if(count != freq1[c]){
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        unordered_map<char, int> freq1, freq2;
        for(char c: s1){
            freq1[c]++;
        }
        for(int i = 0; i < n1; i++){
            freq2[s2[i]]++;
        }
        for(int i = n1; i < n2; i++){
            bool ok = isSame(freq1, freq2);
            if(ok){
                return true;
            }
            freq2[s2[i]]++;
            freq2[s2[i-n1]]--;
        }
        return isSame(freq1, freq2);
    }
};
