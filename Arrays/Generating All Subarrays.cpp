//T.C = O(n^3)
class Solution {
  public:
    vector<vector<int>> getSubArrays(vector<int>& arr) {
        int n = arr.size();
        
        vector<vector<int>> result;
        
        for(int i = 0; i<n; i++) {
            for(int j = i; j<n; j++) {
                vector<int> res;
                for(int k = i; k<=j; k++) {
                    res.push_back(arr[k]);
                }
                result.push_back(res);
            }
        }
        
        return result;
    }
};
