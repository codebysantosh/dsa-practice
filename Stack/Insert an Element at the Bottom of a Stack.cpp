//Approach - I (iterative)
//T.C = O(n)
//S.C = O(n)  
class Solution {
  public:
    stack<int> insertAtBottom(stack<int> st, int x) {
        stack<int> temp;
        
        while(!st.empty()) {
            temp.push(st.top());
            st.pop();
        }
        
        st.push(x);
        
        while(!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }
        
        return st;
    }
};

//Approach - II (recursive)
//T.C = O(n)
//S.C = O(n) system stack 
class Solution {
  public:
    void solve(stack<int> &st, int x) {
        if(st.empty()) {
            st.push(x);
            return;
        }
        
        int temp = st.top();
        st.pop();
        solve(st, x);
        st.push(temp);
    }
  
    stack<int> insertAtBottom(stack<int> st, int x) {
        solve(st, x);
        return st;
    }
};
