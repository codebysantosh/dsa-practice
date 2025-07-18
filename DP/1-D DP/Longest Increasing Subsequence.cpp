//Approach-1 (TopDown: Recur+Memo) 
//T.C : O(n*n)
class Solution {
public:
    int n;
    int t[2501][2501];

    int solve(vector<int>& nums, int idx, int prev) {
        if(idx == n) {
            return 0;
        }

        if(prev != -1 && t[idx][prev] != -1) {
            return t[idx][prev];
        }

        int take = 0;
        if(prev == -1 || nums[idx] > nums[prev]) {
            take = 1 + solve(nums, idx+1, idx);
        }

        int skip = solve(nums, idx+1, prev);

        if(prev != -1) {
            t[idx][prev] = max(take, skip);
        }

        return max(take, skip);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, 0, -1);
    }
};

//Approach-2 (Bottom Up DP) O(n*n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> t(n, 1);
        
        int maxLIS = 1;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                if(nums[i] > nums[j]) {
                    t[i] = max(t[j]+1, t[i]);
                    maxLIS = max(maxLIS, t[i]);
                }
            }
        }

        return maxLIS;
    }
};
