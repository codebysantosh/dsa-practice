//Approach - I (T.C = O(n), S.C = O(n))
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> temp(n);
        temp[0] = INT_MAX;

        for(int i = 1; i<n; i++) {
            temp[i] = min(temp[i-1], prices[i-1]);
        }

        int maxPro = 0;
        for(int i = 0; i<n; i++) {
            int curr = prices[i] - temp[i];
            maxPro = max(maxPro, curr);
        }

        return maxPro;
    }
};

//Approach - II
//T.C = O(n)
//S.C = O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int minPrice = prices[0];
        int maxPro = 0;

        for(int i = 1; i<n; i++) {
            minPrice = min(minPrice, prices[i-1]);

            maxPro = max(maxPro, prices[i] - minPrice);
        }

        return maxPro;
    }
};
