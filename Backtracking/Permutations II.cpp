//Approach-1 (Using same concept as Permutation-I but keeping count to avoid duplicates)
//T.C : O(N * N!)
//S.C : O(N)
class Solution {
public:
    int n;
    vector<vector<int>> result;
    unordered_map<int, int> mp;

    void solve(vector<int> &temp) {
        if(temp.size() == n) {
            result.push_back(temp);
            return;
        }

        for(auto &[curr, count] : mp) {
            if(count == 0) {
                continue;
            }

            temp.push_back(curr);
            mp[curr]--;

            solve(temp);

            temp.pop_back();
            mp[curr]++;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();

        for(int i = 0; i<n; i++) {
            mp[nums[i]]++;
        }

        vector<int> temp;
        solve(temp);
        return result;
    }
};

//Approach-2 (Using swap technique but avoiding duplicates by using set)
//T.C : O(N * N!) worst case
//S.C : O(N)
class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& nums, int idx) {
        if(idx == nums.size()) {
            result.push_back(nums);
            return;
        }

        unordered_set<int> st;

        for(int i = idx; i<nums.size(); i++) {
            if(st.find(nums[i]) != st.end()) {
                continue;  
            }

            st.insert(nums[i]);
            swap(nums[i], nums[idx]);

            solve(nums, idx+1);
            swap(nums[i], nums[idx]);
        } 
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        solve(nums, 0);
        return result;
    }
};
