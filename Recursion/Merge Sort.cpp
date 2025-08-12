//T.C : O(nlogn)
//S.C : O(n)
class Solution {
  public:
    void merge(vector<int> &arr, int mid, int l, int r) {
        int n1 = mid - l + 1;
        int n2 = r - mid;
        
        vector<int> left(n1);
        vector<int> right(n2);
        
        int k = l;
        for(int i = 0; i<n1; i++) {
            left[i] = arr[k];
            k++;
        }
        
        for(int i = 0; i<n2; i++) {
            right[i] = arr[k];
            k++;
        }
        
        int i = 0, j = 0;
        k = l;
        
        while(i < n1 && j < n2) {
            if(left[i] <= right[j]) {
                arr[k] = left[i];
                i++;
            } else {
                arr[k] = right[j];
                j++;
            }
            
            k++;
        }
        
        while(i < n1) {
            arr[k] = left[i];
            i++;
            k++;
        }
        
        while(j < n2) {
            arr[k] = right[j];
            j++;
            k++;
        }
    }
  
    void mergeSort(vector<int>& arr, int l, int r) {
        if(l >= r) {
            return;
        }
        
        int mid = l + (r - l)/2;
        
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        
        merge(arr, mid, l, r);
    }
};
