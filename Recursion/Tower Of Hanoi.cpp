//T.C : O(2^n)
//S.C : O(n) - Recursion Stack Space
class Solution {
  public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        if(n == 1) {
            // cout<< "move disk " << n << " from rod " << from << " to rod " << to;
            return 1;
        }
        
        int count = towerOfHanoi(n-1, from, aux, to);
        
        // cout<< "move disk " << n << " from rod " << from << " to rod " << to;
        count += 1;
        
        count  += towerOfHanoi(n-1, aux, to, from);
        
        return count;
    }
};
