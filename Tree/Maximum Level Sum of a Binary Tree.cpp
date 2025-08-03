//Approach - I (BFS)
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);

        pair<int, int> p = {0, INT_MIN};

        int level = 1;
        while(!q.empty()) {

            int N = q.size();
            int sum = 0;

            while(N--) {

                TreeNode* node = q.front();
                q.pop();
                sum += node->val;

                if(node->left != NULL) {
                    q.push(node->left);
                }

                if(node->right != NULL) {
                    q.push(node->right);
                }
            }

            pair<int, int> temp = {level, sum};

            if(temp.second > p.second) {
                p = temp;
            }

            level++;
        }

        return p.first;
    }
};

//Approach - II (DFS)
class Solution {
public:
    void dfs(TreeNode* root, int level, map<int, int> &mp) {
        if(root == NULL) {
            return;
        }

        mp[level] += root->val;

        dfs(root->left, level+1, mp);
        dfs(root->right, level+1, mp);
    }

    int maxLevelSum(TreeNode* root) {
        map<int, int> mp;
        dfs(root, 1, mp);

        pair<int, int> p {0, INT_MIN};

        for(auto &m : mp) {
            if(m.second > p.second) {
                p = m;
            }
        }

        return p.first;
    }
};
