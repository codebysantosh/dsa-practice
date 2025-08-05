//Approach-1 (With stack)
class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();

        stack<char> st;
        for(int i = 0; i<n; i++) {
            if(!st.empty() && st.top() == s[i]) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        string result = "";
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(begin(result), end(result));
        return result;
    }
};

//Approach - II (without stack)
class Solution {
public:
    string removeDuplicates(string s) {
        string result = "";

        for(auto &ch : s) {
            if(result.empty() || result.back() != ch) {
                result.push_back(ch);
            } else {
                result.pop_back();
            }
        }

        return result;
    }
};
