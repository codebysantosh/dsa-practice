//Approach - I (without loop)
//T.C = O(2^n * n)
//S.C = O(n)
class Solution {
public:
    int n;
    vector<vector<int>> result;

    void solve(vector<int>& nums, int idx, vector<int>& temp) {
        if(idx == n) {
            result.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        solve(nums, idx+1, temp);
        temp.pop_back();

        int i = idx+1;
        while(i < n && nums[i] == nums[i-1]) {
            i++;
        }
        solve(nums, i, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        vector<int> temp;
        sort(begin(nums), end(nums));
        solve(nums, 0, temp);
        return result;
    }
};
