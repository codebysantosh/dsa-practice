//Approach-1 (Simple Recursion)
//T.C : O(2n* (2^(2n)) -> Removing constant -> O(n * (2^n))
//S.C : O(2*n) -> Removing constant -> O(n) -> recursion stack space - Max depth of recusion tree
class Solution {
public:
    bool isValid(string temp) {
        int count = 0;

        for(int i = 0; i<temp.size(); i++) {
            if(temp[i] == '(') {
                count++;
            } else {
                count--;
            }

            if(count < 0) {
                return false;
            }
        }

        return count == 0;
    }

    vector<string> result;
    void solve(int n, string &temp) {
        if(temp.size() == 2*n) {
            if(isValid(temp)) {
                result.push_back(temp);
            }
            return;
        }

        temp.push_back('(');
        solve(n, temp);
        temp.pop_back();

        temp.push_back(')');
        solve(n, temp);
        temp.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        string temp = "";
        solve(n, temp);
        return result;
    }
};
