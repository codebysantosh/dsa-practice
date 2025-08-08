//Approach-1 (BF)
//T.C : O(n^3) - T.L.E : [94 / 103 test cases passed.]
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i<n-2; i++) {
            for(int j = i+1; j<n-1; j++) {
                if(nums[i] < nums[j]) {
                    for(int k = j+1; k<n; k++) {
                        if(nums[i] < nums[k] && nums[k] < nums[j]) {
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }
};

//Approach-2 (Better)
//T.C : O(n^2) - T.L.E : [101 / 103 test cases passed.]
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();

        int nums1 = nums[0];

        for(int j = 1; j<n-1; j++) {
            
            nums1 = min(nums1, nums[j]);

            for(int k = j+1; k<n; k++) {
                if(nums1 < nums[j] && nums1 < nums[k] && nums[k] < nums[j]) {
                    return true;
                }
            }
        }

        return false;
    }
};

//Approach-3 --> Using Monotonic stack
//T.C : O(n) - We don't visit any element more than once
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();

        stack<int> st;
        int num3 = INT_MIN;

        for(int i = n-1; i>=0; i--) {
            if(nums[i] < num3) {
                return true;
            }

            while(!st.empty() && st.top() < nums[i]) {
                num3 = st.top();
                st.pop();
            }

            st.push(nums[i]);
        }

        return false;
    }
};
