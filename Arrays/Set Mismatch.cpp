//T.C = O(n)
//S.C = O(n)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        int missing   = -1;
        int duplicate = -1;

        vector<int> freq(n+1, 0);
        for(int i = 0; i<n; i++) {
            freq[nums[i]]++;
        }

        for(int i = 0; i<=n; i++) {
            if(freq[i] >= 2) {
                duplicate = i;
            } else if(freq[i] == 0) {
                missing = i;
            }
        }

        return {duplicate, missing};
    }
};
