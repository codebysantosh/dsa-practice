//Simple recursive approach
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int sum = 0;

    void dfs(TreeNode* root) {
        if(root == NULL) {
            return;
        }

        dfs(root->right);
      
        sum += root->val;
      
        root->val = sum;
      
        dfs(root->left);
    }

    TreeNode* bstToGst(TreeNode* root) {
        dfs(root);
        return root;
    }
};
