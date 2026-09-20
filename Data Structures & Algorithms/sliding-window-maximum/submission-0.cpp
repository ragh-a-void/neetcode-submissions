class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        int n = nums.size();
        for(int i = 0; i < k; i++){
            pq.push({nums[i], i});
        }
        vector<int> output;
        output.push_back(pq.top().first);
        for(int i = k; i < n; i++){
            int outIdx = i-k;
            pq.push({nums[i], i});
            while(!pq.empty() and pq.top().second <= outIdx){
                pq.pop();
            }
            output.push_back(pq.top().first);
        }
        return output;
    }
};
