//Approach - I (BF)
//T.C = O(n^3)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int maxi = INT_MIN;
        for(int i = 0; i<n; i++) {
            for(int j = i; j<n; j++) {
                int total = 0;
                for(int k = i; k<=j; k++) {
                    total += nums[k];
                }
                maxi = max(maxi, total);
            }
        }

        return maxi;
    }
};

//Approach - II (Better)
//T.C = O(n^2)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int maxi = INT_MIN;
        for(int i = 0; i<n; i++) {
            int total = 0;
            for(int j = i; j<n; j++) {
                cout<<nums[j]<<","<<endl;
                total += nums[j];

                maxi = max(maxi, total);
            }
        }

        return maxi;
    }
};

//Approach - III (kadan's Algorithm)
//T.C = O(n)
//S.C = O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int Currsum = 0;
        int maxi = INT_MIN;
        for(int i = 0; i<n; i++) {
            Currsum += nums[i];

            maxi = max(maxi, Currsum);

            if(Currsum < 0) {
                Currsum = 0;
            }
        }

        return maxi;
    }
};
