//Approach - I (iterative)
//T.C = O(n)
//S.C = O(n)
class Solution {
  public:
    string reverseString(string& s) {
        stack<char> st;
        
        for(int i = 0; i<s.size(); i++) {
            st.push(s[i]);
        }
        
        string res = "";
        
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        
        return res;
    }
};

//Approach - I (recusive)
//T.C = O(n)
//S.C = O(n)
class Solution {
  public:
    void solve(stack<char> &st, string &s, int i) {
        if(i == s.size()) {
            return;
        }
        
        st.push(s[i]);
        solve(st, s, i+1);
    }
  
    string reverseString(string& s) {
        stack<char> st;
        
        solve(st, s, 0);
        
        string res = "";
        
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        
        return res;
    }
};
