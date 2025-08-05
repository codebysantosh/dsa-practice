//Approach - I (recursive)
//T.C = O(n)
//S.C = O(n)
class Solution {
  public:
    void solve(stack<int> &st, vector<int> &temp) {
        if(st.empty()) {
            return;
        }
        
        temp.push_back(st.top());
        st.pop();
        solve(st, temp);
    }
  
    void reverse(stack<int> &st) {
        vector<int> temp;
        solve(st, temp);
        
        for(int i = 0; i<temp.size(); i++) {
            st.push(temp[i]);
        }
    }
};
