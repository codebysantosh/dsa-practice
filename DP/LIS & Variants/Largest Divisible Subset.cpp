//Approach-1 (Using Brute Force same as LIS)
//T.C : O(2^n) without memoization
//S.C : O(n)
class Solution {
public:
    int n;

    void solve(vector<int>& nums, int idx, int prev, vector<int> &temp, vector<int> &result) {
        if(idx == n) {
            if(temp.size() > result.size()) {
                result = temp;
            }

            return;
        } 

        if(prev == -1 || (nums[prev] % nums[idx] == 0 || nums[idx] % nums[prev] == 0)) {
            temp.push_back(nums[idx]);
            solve(nums, idx+1, idx, temp, result);
            temp.pop_back();
        }

        solve(nums, idx+1, prev, temp, result);
    }


    vector<int> largestDivisibleSubset(vector<int>& nums) {
        n = nums.size();
        sort(begin(nums), end(nums));

        vector<int> temp;
        vector<int> result;

        solve(nums, 0, -1, temp, result);

        return result;
    }
};

//Approach-2 (Using Bottom Up same as LIS) - Just need to keep track of how to print LIS
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int n = nums.size();
        vector<int> t(n, 1);

        vector<int> prev_idx(n, -1);
        int last_chosen_index = 0;
        int maxL = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i]%nums[j] == 0) {
                    if(t[i] < t[j]+1) {
                        t[i] = t[j]+1;
                        prev_idx[i] = j;
                    }

                    if(t[i] > maxL) {
                        maxL = t[i];
                        last_chosen_index = i;
                    }
                }
            }
        }

        vector<int> result;
        while(last_chosen_index >= 0) {
            result.push_back(nums[last_chosen_index]);
            last_chosen_index = prev_idx[last_chosen_index];
        }

        return result;
    }
};
