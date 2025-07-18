//Approach-1 (Recur + Memo)
class Solution {
public:
    int t[101];

    int solve(vector<int>& nums, int idx, int n) {
        if(idx > n) {
            return 0;
        }

        if(t[idx] != -1) {
            return t[idx];
        }

        int steal = nums[idx] + solve(nums, idx+2, n); //steals ith house and moves to i+2 (because we can't steal adjacent)
        int skip = solve(nums, idx+1, n); //skips this house, now we can move to adjacent next house

        return t[idx] = max(steal, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) {
            return nums[0];
        }

        if(n == 2) {
            return max(nums[0], nums[1]);
        }

        memset(t, -1, sizeof(t));

        //case-1 - Take first house 0th index wala house
        int take_first = solve(nums, 0, n-2);

        memset(t, -1, sizeof(t));

         //case-2  - Take second house 1st index wala house
        int not_take_first = solve(nums, 1, n-1);

        return max(take_first, not_take_first);
    }
};

//Approach-2 (Using Bottom Up similar to House Robber-1 and just taking two cases
/*
    Case-1 (Take from 1st House - Hence skip the last house)
    Case-2 (Take from 2nd House - Hence take the last house)
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) {
            return nums[0];
        }

        vector<int> t(n+1, 0);
        //t[i] = Max money gained from i houses

        int result1 = 0;
        int result2 = 0;

        t[0] = 0;
        //Case-1 (Take from 1st House - Hence skip the last house)
        for(int i = 1; i<=n-1; i++) {
            int skip = t[i-1];
            int steal = nums[i-1] + ((i - 2 >= 0) ? t[i-2] : 0);

            t[i] = max(steal, skip);
        }
        result1 = t[n-1];

        t = vector<int>(n+1, 0);
        //Case-2 (Take from 2nd House - Hence take the last house)
        t[0] = 0;
        t[1] = 0;
        for(int i = 2; i<=n; i++) {
            int steal = nums[i-1] + t[i-2];
            int skip = t[i-1];

            t[i] = max(steal, skip); 
        }
        result2 = t[n];

        return max(result1, result2);
    }
};

//Approach-3 (Converting Bottom Up to constant space)
class Solution {
public:
    int solve(vector<int>& nums, int l, int r) {
        int prevprev = 0, prev = 0;

        for(int i = l; i<=r; i++) {
            int steal = nums[i] + prevprev;
            int skip = prev;

            int temp = max(steal, skip);

            prevprev = prev;
            prev = temp;
        }

        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) {
            return nums[0];
        }

        int take_first_house = solve(nums, 0, n-2);
        int skip_first_house = solve(nums, 1, n-1);

        return max(take_first_house, skip_first_house);
    }
};
