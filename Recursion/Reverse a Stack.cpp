//Approach-1 (Using O(n) Auxiliary Space (we took extra one temp stack))
//Time : O(n^2)
//Space : O(n)
class Solution {
  public:
    void solve(stack<int> &st) {
        if(st.empty()) {
            return;
        }
        
        int val = st.top();
        st.pop();
        solve(st);
        
        stack<int> temp;
        
        while(!st.empty()) {
            temp.push(st.top());
            st.pop();
        }
        st.push(val);
        
        while(!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }
    }
  
    void reverse(stack<int> &St) {
        solve(St);
    }
};

//Approach-2 (Using O(1) Auxiliary Space)
//Time : O(n^2)
//Space : O(1) 
class Solution {
  public:
    void insertAtBottom(stack<int> &st, int x) {
        if(st.empty()) {
            st.push(x);
            return;
        }
        
        int val = st.top();
        st.pop();
        insertAtBottom(st, x);
        st.push(val);
    }
  
    void solve(stack<int> &st) {
        if(st.empty()) {
            return;
        }
        
        int val = st.top();
        st.pop();
        solve(st);
        
        insertAtBottom(st, val);
    }
  
    void reverse(stack<int> &St) {
        solve(St);
    }
};
