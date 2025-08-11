//Approach - I (BF)
//T.C = O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                if(nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        return {};
    }
};

//Approach - I (using mp)
//T.C = O(n)
//S.C = O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for(int i = 0; i<nums.size(); i++) {
            int curr = target - nums[i];
            
            if(mp.find(curr) != mp.end()) {
                return {mp[curr], i};
            } else {
                mp[nums[i]] = i;
            }
        }

        return {};
    }
};
