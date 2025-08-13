//Approach-1 (Swapping elements in nums)
class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& nums, int idx) {
        if(idx == nums.size()) {
            result.push_back(nums);
            return;
        }

        for(int i = idx; i<nums.size(); i++) {
            swap(nums[i], nums[idx]);
            solve(nums, idx+1);
            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums, 0);
        return result;
    }
};

//Approach - II (A very general Backtracking pattern which can help solve subsets, Subsets II, Permutations, Permutations II,  Combination Sum, Combination Sum II as well.
//T.C = (n * n!)
//S.C = (n)
class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& nums, vector<int>& temp, unordered_set<int>& st) {
        if(temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }

        for(int i = 0; i<nums.size(); i++) {
          
            if(st.find(nums[i]) == st.end()) {
                temp.push_back(nums[i]);
                st.insert(nums[i]);
              
                solve(nums, temp, st);
              
                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        unordered_set<int> st;
      
        solve(nums, temp, st);
        return result;
    }
};
