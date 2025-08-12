//Approach - I
//T.C = O(m+n)
//S.C = O(m+n)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp1(m);
        vector<int> temp2(n);

        for(int i = 0; i<m; i++) {
            temp1[i] = nums1[i]; 
        }

        for(int j = 0; j<n; j++) {
            temp2[j] = nums2[j];
        }

        int i = 0, j = 0;
        int k = 0;
        while(i < m && j < n){
            if(temp1[i] <= temp2[j]) {
                nums1[k] = temp1[i];
                k++;
                i++;
            } else {
                nums1[k] = temp2[j];
                k++;
                j++;
            }
        }

        while(i < m) {
            nums1[k] = temp1[i];
            k++;
            i++;
        }

        while(j < n) {
            nums1[k] = temp2[j];
            k++;
            j++;
        }
    }
};
