//Approach 1 - Brute Force
//T.C : O(m⋅log10​M + n⋅log10​N)
//S.C : O(m⋅log10​M)
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;

        //123
        //st : {123, 12, 1, 12345, 1234, }
        for(int val : arr1) {
            while(!st.count(val) && val > 0) {
                st.insert(val);

                val = val/10;
            }
        }


        int result = 0; //LCP
        for(int num : arr2) {
            while(!st.count(num) && num > 0) {
                num /= 10;
            }

            if(num > 0) {
                result = max(result, static_cast<int>(log10(num)) + 1);
            }
        }

        return result;
    }
};

//Approach 2 - Using Prefix Tree (TRIE)
//T.C : O(m⋅d+n⋅d)
//S.C : O(m⋅d)
class Solution {
public:
    struct trieNode {
        trieNode* child[10];
    };

    trieNode* getNode() {
        trieNode* newNode = new trieNode();

        for(int i = 0; i<10; i++) {
            newNode->child[i] = NULL;
        }

        return newNode;
    }

    void insert(int num, trieNode* root) {
        trieNode* crawler = root;
        string s = to_string(num);

        for(char ch : s) {
            int digit = ch - '0';
            if(crawler->child[digit] == NULL) {
                crawler->child[digit] = getNode();
            }

            crawler = crawler->child[digit];
        }
    }

    int search(trieNode* root, int num) {
        trieNode* crawler = root;
        string s = to_string(num);

        int res = 0;
        for(char ch : s) {
            int digit = ch - '0';
            if(crawler->child[digit] == NULL) {
                return res;
            }
            
            res++;
            crawler = crawler->child[digit];
        }

        return res;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int m = arr1.size();
        int n = arr2.size();

        trieNode* root = getNode();

        for(int i = 0; i<m; i++) {
            insert(arr1[i], root);
        }

        int result = 0;
        for(int i = 0; i<n; i++) {
            int temp = search(root, arr2[i]);
            result = max(result, temp);
        }

        return result;
    }
};
