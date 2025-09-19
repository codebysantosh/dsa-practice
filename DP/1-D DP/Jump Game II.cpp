//Approach - I(not return)
class Solution {
public:
    int ans = INT_MAX;
    void solve(vector<int> &nums, int n, int idx, int j) {
        if(idx >= n-1) {
            ans = min(ans, j);
            return;
        }

        for(int i = 1; i<=nums[idx]; i++) {
            solve(nums, n, i+idx, j+1);
        }
    }

    int jump(vector<int>& nums) {
        int n = nums.size();

        solve(nums, n, 0, 0);

        return ans;
    }
};

//Approach - I (return)
class Solution {
public:
    int t[10001];

    int solve(vector<int>& nums, int n, int idx) {
        if(idx >= n-1) return 0;

        if(t[idx] != -1) {
            return t[idx];
        }

        int ans = INT_MAX;
        for(int i = 1; i<=nums[idx]; i++) {
            int step = solve(nums, n, idx+i);
            if(step != INT_MAX) {
                ans = min(ans, 1 + step);
            }
        }

        return t[idx] =  ans;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, n, 0);
    }
};

//Approach - II (Bottom up)
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int> t(n, INT_MAX);

        t[0] = 0;
        for(int i = 1; i<n; i++) {

            for(int j = i-1; j>=0; j--) {

                if(j + nums[j] >= i) {
                    int step = t[j] + 1;
                    t[i] = min(t[i], step);
                }
            }
        }

        return t[n-1];
    }
};

//Smart Approach
