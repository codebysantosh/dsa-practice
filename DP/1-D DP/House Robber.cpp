//Approach-1 (Recur + Memo)
class Solution {
public:
    int n;
    int t[101];

    int solve(vector<int>& nums, int idx) {
        if(idx >= n) {
            return 0;
        }

        if(t[idx] != -1) {
            return t[idx];
        }

        int take = nums[idx] + solve(nums, idx+2);
        int skip = solve(nums, idx+1);

        return t[idx] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, 0);
    }
};

//Approach-2 (Bottom up)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n+1, 0);

        //t[i] = max stolen money till i house

        t[0] = 0;
        t[1] = nums[0];

        for(int i = 2; i<n+1; i++) {
            int steal = nums[i-1] + t[i-2];
            int skip = t[i-1];

            t[i] = max(steal, skip);

            /*
                SKIP  : If we skip this house,  then we have money till previous house  =  t[i-1]
                STEAL : If we steal this house, then we can't take prev profit, we can take till (i-2)th house profit = t[i-2]
            */
        }

        return t[n];
    }
};

//Approach-3 (Space Optimized Bottom Up - Converting Approach-2)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        int prevprev = 0;
        int prev = nums[0];

        for(int i = 2; i<=n; i++) {
            int take = nums[i-1] + prevprev;
            int skip = prev;

            int temp = max(take, skip);

            prevprev = prev;
            prev = temp;
        }

        return prev;
    }
};
