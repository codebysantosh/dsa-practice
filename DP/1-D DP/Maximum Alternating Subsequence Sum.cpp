//Approach-1 (Recursion + Memo) (Time Complexity - n*2 : We visit all states of t once)
class Solution {
public:
    int n;
    long long t[100001][2];

    long long solve(vector<int>& nums, int idx, bool iseven) {
        if(idx >= n) {
            return 0;
        }

        if(t[idx][iseven] != -1) {
            return t[idx][iseven];
        }

        long long skip = solve(nums, idx+1, iseven);
        int val = nums[idx];

        if(iseven == false) {
            val = -val;
        }

        long long take = val + solve(nums, idx+1, !iseven);

        return t[idx][iseven] = max(take, skip);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, 0, true);
    }
};

//Approach-2 (Bottom Up) -- T.C : O(n), space : O(n)
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long n = nums.size();

        vector<vector<long>> t(n+1, vector<long> (2, 0)); //even : 0, odd : 1

        for(int i = 1; i<n+1; i++) {
            
            //even
            t[i][0] = max(t[i-1][1] - nums[i-1], t[i-1][0]);

            //odd
            t[i][1] = max(t[i-1][0] + nums[i-1], t[i-1][1]);

        }

        return max(t[n][0], t[n][1]);
    }
};
