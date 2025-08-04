//Approach - I (BF)
//T.C = (n*n)
//S.C = (n)
class Solution {
public:
    vector<int> sorted;

    void dfs(TreeNode* root) {
        if(root == NULL) {
            return;
        }

        dfs(root->left);
        sorted.push_back(root->val);
        dfs(root->right);
    }

    int getSum(int val) {
        int n = sorted.size();

        int sum = 0;
        for(int i = n-1; i>=0; i--) {
            sum += sorted[i];
            if(sorted[i] == val) break;
        }

        return sum;
    }

    void gst(TreeNode* root) {
        if(root == NULL) {
            return;
        }

        root->val = getSum(root->val);

        gst(root->left);
        gst(root->right);
    }

    TreeNode* bstToGst(TreeNode* root) {
        dfs(root);
        gst(root);

        return root;
    }
};

//Simple recursive approach (op)
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
