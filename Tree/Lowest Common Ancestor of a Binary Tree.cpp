//optimize approach
class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) {
            return NULL;
        }

        if(root == p || root == q) {
            return root;
        }

        TreeNode* left = solve(root->left, p, q);
        TreeNode* right = solve(root->right, p, q);

        if(left != NULL && right != NULL) {
            return root;
        }

        return left == NULL ? right : left;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};

//Brute force
class Solution {
public:
    bool solve(TreeNode* root, TreeNode* x, vector<TreeNode*> &path) {
        if(root == NULL) {
            return false;
        }

        path.push_back(root);

        if(root == x) {
            return true;
        }

        if(solve(root->left, x, path) || solve(root->right, x, path)) {
            return true;
        }

        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;

        solve(root, p, path1);
        solve(root, q, path2);

        TreeNode* lca = NULL;
        for(int i = 0, j = 0; i<path1.size() && j < path2.size(); i++, j++) {
            if(path1[i] != path2[j]) {
                break;
            }
            lca = path1[i];
        }

        return lca;
    }
};
