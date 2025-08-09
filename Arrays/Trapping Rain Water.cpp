//Approach - I 
//T.C = O(n)
//S.C = O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> leftMax(n), rightMax(n);
        leftMax[0]  = height[0];
        rightMax[n-1] = height[n-1];

        for(int i = 1; i<n; i++) {
            leftMax[i] = max(leftMax[i-1], height[i]);
            cout<<leftMax[i];
        }

        for(int i = n-2; i>=0; i--) {
            rightMax[i] = max(rightMax[i+1], height[i]);
            cout<<rightMax[i];
        }

        int maxTrap = 0;
        for(int i = 0; i<n; i++) {
            int curr = min(leftMax[i], rightMax[i]) - height[i];
            
            if(curr > 0) {
                maxTrap += curr;
            }
        }

        return maxTrap;
    }
};

//Approach - II 
//T.C = O(n)
//S.C = O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int i = 0, j = n-1;
        int left  = height[0], right = height[n-1];

        int maxTrap = 0;
        while(i < j) {
            left  = max(left, height[i]);
            right = max(right, height[j]);

            if(left <= right) {
                maxTrap += left - height[i];
                i++;
            } else {
                maxTrap += right - height[j];
                j--;
            }
        }

        return maxTrap;
    }
};
