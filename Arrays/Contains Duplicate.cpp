//Approach - I (sorting)
//T.C = O(nlogn)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        for(int i = 1; i<n; i++) {
            if(nums[i-1] == nums[i]) {
                return true;
            }
        }

        return false;
    }
};
