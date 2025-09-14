class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int minPrice = prices[0];
        int maxProfit = 0;
        int totalProfit = 0;
        for(int i = 1; i<n; i++) {
            
            maxProfit = max(maxProfit, (prices[i] - minPrice));

            if(maxProfit != 0) {
                totalProfit += maxProfit;
                maxProfit = 0;
                minPrice = prices[i];
            }

            minPrice = min(minPrice, prices[i]);
        }

        return totalProfit;
    }
};
