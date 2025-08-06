//Approach-1 (Simple Brute Force) - TLE
//T.C : O(n^3)
//S.C : O(1)
class Solution {
public:
    int MOD = 1e9 + 7;

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        long long result = 0;
        for(int i = 0; i<n; i++) {
            for(int j = i; j<n; j++) {
                int mini = INT_MAX;
                for(int k = i; k<=j; k++) {
                    mini = min(mini, arr[k]);
                }
                result = (result + mini)%MOD;
            }
        }

        return (int)result;
    }
};

//Approach-2 (Simple Brute Force) - TLE
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int M = 1e9 + 7;
    int sumSubarrayMins(std::vector<int>& arr) {
        int n = arr.size();
        long result = 0;

        for (int i = 0; i < n; i++) {
            int minVal = arr[i];

            for (int j = i; j < n; j++) {
                minVal = min(minVal, arr[j]);
                result = (result + minVal) % M;
            }
        }

        return result;
    }
};

//Approach-3
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    //This is just we are finding next smaller to each element to left
    //Similar : Leetcode-84
    vector<int> getNSL(vector<int> &arr, int n) {
        vector<int> result(n);
        stack<int> st;

        for(int i = 0; i<n; i++) {
            if(st.empty()) {
                result[i] = -1;
            } else {
                while(!st.empty() && arr[st.top()] >= arr[i]) { //non-strictly less
                    st.pop();
                }

                result[i] = st.empty() ? -1 : st.top();
            }

            st.push(i);
        }

        return result;
    }

    //This is just we are finding next smaller to each element to right
    //Similar : Leetcode-84
    vector<int> getNSR(vector<int> &arr, int n) {
        vector<int> result(n);
        stack<int> st;

        for(int i = n-1; i>=0; i--) {
            if(st.empty()) {
                result[i] = n;
            } else {
                while(!st.empty() && arr[st.top()] > arr[i]) { //strictly less
                    st.pop();
                }

                result[i] = st.empty() ? n : st.top();
            }

            st.push(i);
        }

        return result;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> NSL = getNSL(arr, n);
        vector<int> NSR = getNSR(arr, n);

        long long sum = 0;
        int MOD = 1e9+7;

        for(int i = 0; i<n; i++) {

            long long ls = i - NSL[i]; //distance to nearest smaller to left from i
            
            long long rs = NSR[i] - i; //distance to nearest smaller to right from i

            long long prod = ls*rs;
            long long total = arr[i]*prod;

            sum = (sum + total) % MOD;
        }

        return (int)sum;
    }
};
