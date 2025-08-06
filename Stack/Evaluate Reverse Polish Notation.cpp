//Approach-1 (Basic stack approach)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int operate(int a, int b, string s) {
        if(s == "+") {
            return a + b;
        }
        if(s == "-") {
            return a - b;
        }
        if(s == "*") {
            return (long)a * (long)b;
        }
        if(s == "/") {
            return a / b;
        }

        return -1;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string &token : tokens) {
            if(token == "+" || token == "-" || token == "*" || token == "/") {

                int a  = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                int result = operate(b, a, token);

                st.push(result);
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};

// Using fancy Lambda on unordered_map
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        unordered_map<string, function<int(int, int)>> mp = {
            {"+", [](int a, int b) {return a + b;}},
            {"-", [](int a, int b) {return a - b;}},
            {"*", [](int a, int b) {return (long)a * (long)b;}},
            {"/", [](int a, int b) {return a / b;}},
        };

        for(string &token : tokens) {
            if(token == "+" || token == "-" || token == "*" || token == "/") {

                int a  = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                int result = mp[token](b, a);

                st.push(result);
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
