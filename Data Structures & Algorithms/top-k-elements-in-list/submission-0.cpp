class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(auto num: nums){
            freq[num]++;
        }
        vector<pair<int, int>> freqNum;
        for(auto [num, f]: freq){
            freqNum.push_back({f, num});
        }
        sort(freqNum.begin(), freqNum.end(), greater<pair<int, int>>());
        vector<int> output;
        for(int i = 0; i < k; i++){
            output.push_back(freqNum[i].second);
        }
        return output;
    }
};
