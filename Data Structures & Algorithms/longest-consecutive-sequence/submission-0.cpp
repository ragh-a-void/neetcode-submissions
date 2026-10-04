class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int output = 0;
        for(auto num: numSet){
            if(!numSet.count(num-1)){
                int currCount = 0, currNum = num;
                while(numSet.count(currNum)){
                    currCount++;
                    currNum++;
                }
                output = max(output, currCount);
            }
        }
        return output;
    }
};
