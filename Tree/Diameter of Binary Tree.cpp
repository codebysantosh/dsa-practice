//Approache - I (DFS) 
//T.C : O(n)
//S.C : O(depth of tree) - Recursion System Stack Space
class Solution {
public:
    int dfs(TreeNode* root, int &result) {
        if(root == NULL) {
            return 0;
        }

        int left = dfs(root->left, result);
        int right = dfs(root->right, result);

        result = max(result, left + right); //What if I longest diamenter passes through left -> me -> right
        
        int curr = max(left, right) + 1; 

        return curr; //But I will return max I can afford if (left -> me -> right) was not answer
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int result = INT_MIN;
        dfs(root, result);
        return result;
    }
};
