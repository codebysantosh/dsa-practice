//Tc = (N*M)
class Solution {
public:
    bool checkSubRoot(TreeNode* root, TreeNode* subRoot) { //(M)
        if(!root && !subRoot) {
            return true;
        }

        if(!root || !subRoot) {
            return false;
        }

        return root->val == subRoot->val && checkSubRoot(root->left, subRoot->left) && checkSubRoot(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) { //(N)
        if(root == NULL) {
            return false;
        }

        if(checkSubRoot(root, subRoot)) {
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
