//Approach-1 (Using Stack)
class Solution {
public:
    string removeStars(string s) {
        stack<char> st;

        for(auto ch : s) {
            if(ch == '*') {
                st.pop();
            } else {
              st.push(ch);
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

//Approach-2 (using string as stack)
class Solution {
public:
    string removeStars(string s) {
        string result = "";

        for(auto &ch : s) {
            if(ch == '*') {
                result.pop_back();
            } else {
              result.push_back(ch);
            }
        }

        return result;
    }
};

//Approach-3 (Using Two pointers)
class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        vector<char> temp(n);

        int j = 0;
        for(int i = 0; i<n; i++) {
            if(s[i] == '*') {
                j--;
            } else {
              temp[j++] = s[i];
            }
        }

        string ans = "";
        for(int i = 0; i<j; i++) {
            ans.push_back(temp[i]);
        }

        return ans;
    }
};
