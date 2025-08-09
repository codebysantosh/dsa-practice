class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxTillNow = nums[0];
        int minTillNow = nums[0];
        int ans = nums[0];

        for(int i = 1; i<n; i++) {
            int curr = nums[i];

            int tempMax = max({curr, maxTillNow*curr, minTillNow*curr});
            minTillNow  = min({curr, maxTillNow*curr, minTillNow*curr});

            maxTillNow = tempMax;

            ans = max(maxTillNow, ans);
        }

        return ans;
    }
};
