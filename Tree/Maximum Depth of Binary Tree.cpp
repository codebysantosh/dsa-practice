//Approach - I (BFS)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int ht = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            int N = q.size();

            while(N--) {

                TreeNode* node = q.front();
                q.pop();

                if(node->left != NULL) {
                    q.push(node->left);
                }

                if(node->right != NULL) {
                    q.push(node->right);
                }
            }
            ht++;
        }

        return ht;
    }
};

//Approach - II (DFS)
class Solution {
public:
    int dfs(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int left  = 1 + dfs(root->left);
        int right = 1 + dfs(root->right);

        return max(left, right);
    }

    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
};
