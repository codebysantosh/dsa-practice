//Approach-1 (Without For Loop)
//T.C : O(n * 2^n) - For ever index, we have two possibilities so 2^n and for copying each string to result, it takes O(n)
//S.C : O(n) - Recursion tree depth will be at max  = n  (NOTE : I have ignored space taken for storing result)
class Solution {
  public:
    vector<string> result;
  
    void solve(string &s, int idx, string &temp) {
        if(idx == s.size()) {
            if(!temp.empty()) {
                result.push_back(temp);
            }
            return;
        }
        
        temp.push_back(s[idx]);
        solve(s, idx+1, temp);
        temp.pop_back();
        solve(s, idx+1, temp);
    }
  
    vector<string> AllPossibleStrings(string s) {
        string temp = "";
        solve(s, 0, temp);
        sort(begin(result), end(result));
        return result;
    }
};
