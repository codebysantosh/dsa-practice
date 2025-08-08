//T.C = O(n)
class Solution {
  public:
    int largest(vector<int> &arr) {
        int n = arr.size();
        
        int largest = INT_MIN;
        
        for(int i = 0; i<n; i++) {
            largest = max(arr[i], largest);
        }
        
        return largest;
    }
};
