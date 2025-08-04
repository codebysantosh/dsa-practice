//Approach - I 
//T.C = O(n)
//S.C = O(n)
class Solution {
public:
    void inOrder(TreeNode* root, unordered_map<int, int> &mp) {
        if(root == NULL) {
            return;
        }

        inOrder(root->left, mp);
        mp[root->val]++;
        inOrder(root->right, mp);
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mp;
        inOrder(root, mp);

        int maxFreq = 0;
        vector<int> result;

        for(auto &it : mp) {

            if(it.second > maxFreq) {
                maxFreq = it.second;
                result = {};
                result.push_back(it.first);
            } else if(it.second == maxFreq) {
                result.push_back(it.first);
            }
        }

        return result;
    }
};

//Approach - II 
//T.C = O(n)
//S.C = O(1)
class Solution {
public:
    vector<int> result;
    int currNum = 0;
    int currFreq = 0;
    int maxFreq = 0;

    void dfs(TreeNode* root) {
        if(root == NULL) {
            return;
        }

        dfs(root->left);

        if(currNum != root->val) {
            currNum = root->val;
            currFreq = 1;
        } else {
            currFreq++;
        }

        if(currFreq > maxFreq) {
            maxFreq = currFreq;
            result = {};
            result.push_back(root->val);
        } else if(currFreq == maxFreq) {
            result.push_back(root->val);
        }

        dfs(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return result;
    }
};
