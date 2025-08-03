//Approache - I (BFS)
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);

        int count = 1;
        while(!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            if(node->left != NULL) {
                q.push(node->left);
                count++;
            }

            if(node->right != NULL) {
                q.push(node->right);
                count++;
            }
        }

        return count;
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

        return left+right-1;
    }

    int countNodes(TreeNode* root) {
        return dfs(root);
    }
};
