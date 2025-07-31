//T.C : O(32*n)
class Solution {
public:
    struct trieNode {
        trieNode* left;
        trieNode* right;
    };

    void insert(int num, trieNode* root) {
        trieNode* crawler = root;

        for(int i = 31; i>=0; i--) {
            int ith_bit = (num >> i) & 1;

            if(ith_bit == 1) {
                if(crawler->right == NULL) {
                    crawler->right = new trieNode();
                }

                crawler = crawler->right;
            } else {
                if(crawler->left == NULL) {
                    crawler->left = new trieNode();
                }

                crawler = crawler->left;
            }
        }
    }

    int findMaxXOR(int num, trieNode* root) {
        trieNode* crawler = root;

        int maxXor = 0;
        for(int i = 31; i>=0; i--) {
            int ith_bit = (num >> i) & 1;

            if(ith_bit == 1) {
                if(crawler->left != NULL) {
                    maxXor += pow(2, i);
                    crawler = crawler->left;
                } else {
                    crawler = crawler->right;
                }
            } else {
                if(crawler->right != NULL) {
                    maxXor += pow(2, i);
                    crawler = crawler->right;
                } else {
                    crawler = crawler->left;
                }
            }
        }

        return maxXor;
    }

    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();

        trieNode* root = new trieNode();

        for(int x : nums) {
            insert(x, root);
        }

        int result = 0;
        for(auto x : nums) {
            int temp = findMaxXOR(x, root);
            result = max(result, temp);
        }

        return result;
    }
};
