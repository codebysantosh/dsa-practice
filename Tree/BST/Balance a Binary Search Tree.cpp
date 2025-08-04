//Simple approach using inordere tree traversal
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    void inOrder(TreeNode* root, vector<int> &sorted) {
        if(root == NULL) {
            return;
        }

        inOrder(root->left, sorted);
        sorted.push_back(root->val);
        inOrder(root->right, sorted);
    }

    TreeNode* construct(int l, int r, vector<int> vec) {
        if(l > r) {
            return NULL;
        }

        int mid = l + (r - l)/2;
        TreeNode* root = new TreeNode(vec[mid]);

        root->left  = construct(l, mid-1, vec);
        root->right = construct(mid+1, r, vec);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sorted;
        inOrder(root, sorted);

        int l = 0;
        int r = sorted.size()-1;

        return construct(l, r, sorted);
    }
};
