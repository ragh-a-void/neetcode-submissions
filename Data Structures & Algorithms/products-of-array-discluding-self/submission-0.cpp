class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);
        output[n-1] = 1;
        for(int i = n-2; i >= 0; i--){
            output[i] = nums[i+1] * output[i+1];
        }
        int prefixProduct = 1;
        for(int i = 0; i < n; i++){
            output[i] = output[i] * prefixProduct;
            prefixProduct *= nums[i];
        }
        return output;
    }
};
