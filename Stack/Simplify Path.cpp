//Approach-1 (Using Stack)
class Solution {
public:
    string simplifyPath(string path) {
        string token = "";
        stack<string> st;

        stringstream ss(path);

        while(getline(ss, token, '/')) {

            if(token == "." || token == "") continue;

            if(token != "..") {
                st.push(token);
            } else if(!st.empty()){
                st.pop();
            }
        }

        if(st.empty()) {
            return "/";
        }

        string result = "";

        while(!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        return result;
    }
};

//Approach-2 (Using vector as stack)
class Solution {
public:
    string simplifyPath(string path) {
        string token = "";
        vector<string> vec;

        stringstream ss(path);

        while(getline(ss, token, '/')) {

            if(token == "." || token == "") continue;

            if(token != "..") {
                vec.push_back(token);
            } else if(!vec.empty()){
                vec.pop_back();
            }
        }

        string result = "";

        for(auto &token : vec) {
            result = result + "/" + token;
        }

        return result.empty() ? "/" : result;
    }
};
};
