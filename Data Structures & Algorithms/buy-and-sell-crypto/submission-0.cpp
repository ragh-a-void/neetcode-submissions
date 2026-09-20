class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = -1, maxProfit = 0;
        for(auto price: prices){
            if(minPrice > -1){
                maxProfit = max(maxProfit, price - minPrice);
                minPrice = min(minPrice, price);
            }else{
                minPrice = price;
            }
        }
        return maxProfit;
    }
};
