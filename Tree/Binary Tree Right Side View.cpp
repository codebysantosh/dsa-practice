//Approach - 1 (DFS)
class Solution {
public:
    void preOrder(TreeNode* root, vector<int> &result, int ht) {
        if(root == NULL) {
            return;
        }

        if(result.size() < ht) {
            result.push_back(root->val);
        }

        preOrder(root->right, result, ht+1);
        preOrder(root->left, result, ht+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        preOrder(root, result, 1);
        return result;
    }
};

//Approach-2 (Level Order Traversal)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) {
            return {};
        }

        vector<int> result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            
            int N = q.size();
            TreeNode* node = NULL;

            while(N--) {

                node = q.front();
                q.pop();

                if(node->left != NULL) {
                    q.push(node->left);
                }
                if(node->right != NULL) {
                    q.push(node->right);
                }
            }

            result.push_back(node->val);
        }

        return result;
    }
};
