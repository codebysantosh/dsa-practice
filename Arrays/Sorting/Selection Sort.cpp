//T.C = O(n^2)
class Solution {
  public:
    void selectionSort(vector<int> &arr) {
        int n = arr.size();
        
        for(int i = 0; i<n; i++) {
            
            int minIdx = i;
            
            for(int j = i+1; j<n; j++) {
                
                minIdx = arr[j] < arr[minIdx] ? j : minIdx;
                
            }
            
            swap(arr[i], arr[minIdx]);
        }
    }
};
