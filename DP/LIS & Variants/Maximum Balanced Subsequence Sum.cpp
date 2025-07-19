//Approach-1 (Using LIS) - Recursion + Memoization (TLE) ---> 341 / 345 testcases passed
//T.C : O(n^2) - prev index for every iclass Solution {
public:
    int n;
    unordered_map<string, long long> mp;

    long long solve(vector<int>& nums, int idx, int prev) {
        if(idx == n) {
            return 0;
        }

        string key = to_string(idx) + "_" + to_string(prev);
        if(mp.find(key) != mp.end()) {
            return mp[key];
        }

        long long take = 0;
        if(prev == -1 || (nums[idx] - nums[prev] >= idx - prev)) {
            take = nums[idx] + solve(nums, idx+1, idx);
        }

        long long not_taken = solve(nums, idx+1, prev);

        return mp[key] = max<long long>(take, not_taken);
    }

    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        n = nums.size();

        auto maxEl = *max_element(nums.begin(), nums.end());
        if(maxEl <= 0) {
            return maxEl;
        }

        return solve(nums, 0, -1);
    }
};

//Approach-2 (Using LIS Bottom Up) - TLE (341/345 Test cases passed)
//Time : O(n^2)
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();

        auto maxEl = *max_element(begin(nums), end(nums));
        if(maxEl <= 0) {
            return maxEl;
        }

        vector<long> t(n);
        for(int i = 0; i<n; i++) {
            t[i] = nums[i];
        }

        long long maxSum = INT_MIN;
        for(int i = 0; i<n; i++) {
          
            for(int j = 0; j<i; j++) {
              
                if(nums[i] - i >= nums[j] - j) {
                    t[i] = max<long long>(t[i], t[j] + nums[i]);
                    maxSum = max<long long>(maxSum, t[i]);
                }
            }
        }

        return maxSum > maxEl ? maxSum : maxEl;
    }
};

//Approach-3 (Using Optimal LIS - Similar to Patience Sorting) - Accepted
//Time : O(nlogn)
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        map<int, long long> mp;

        long long result = INT_MIN;

        for(int i = 0; i<n; i++) {

            auto it = mp.upper_bound(nums[i]-i); //Find the element just greater than nums[i]-i;

            long long sum = nums[i];

            if(it != mp.begin()) {
                it--;
                sum += it->second;
            }

            mp[nums[i]-i] = max(mp[nums[i] - i], sum);

            it = mp.upper_bound(nums[i]-i);

            while(it != mp.end() && it->second <= sum) {
                mp.erase(it++);
            }

            result = max(result, sum);
        }

        return result;
    }
};
