//T.C : O(nlogn) in Average case, O(n^2) in worst case
//S.C : O(1) Auxiliary space
class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        if(low >= high) {
            return;
        }
        
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[hight];
        
        int pi = low;
        for(int i = low; i<high; i++) {
            if(arr[i] < pivot) {
                swap(arr[pi], arr[i]);
                pi++;
            }
        }
        
        swap(arr[pi], arr[high]);
        
        return pi;
    }
};
