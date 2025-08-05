//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        stack<int> st;
        vector<int> result;

        for(int i = n-1; i>=0; i--) {
            
            while(!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            if(st.empty()) {
                result.push_back(0);
            } else {
                result.push_back(st.top() - i); //days
            }
            st.push(i);
        }

        reverse(begin(result), end(result));
        return result;
    }
};
