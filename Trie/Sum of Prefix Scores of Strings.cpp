//Approach - Using TRIE 
//T.C : O(n*l), n = number of words, l = average length of each word
//S.C : O(n*l), need to store all characters of words
class Solution {
public:
    struct trieNode {
        int countp;
        trieNode* child[26];
    };

    trieNode* getNode() {
        trieNode* newNode = new trieNode();

        newNode->countp = 0;

        for(int i = 0; i<26; i++) {
            newNode->child[i] = NULL;
        }

        return newNode;
    }

    void insert(trieNode* root, string word) {
        trieNode* crawler = root;

        for(int i = 0; i<word.size(); i++) {
            int ch_idx = word[i]-'a';

            if(crawler->child[ch_idx] == NULL) {
                crawler->child[ch_idx] = getNode();
            }

            crawler->child[ch_idx]->countp++;
            crawler = crawler->child[ch_idx];
        }
    }

    int search(string word, trieNode* root) {
        trieNode* crawler = root;

        int score = 0;
        for(int i = 0; i<word.size(); i++) {
            int ch_idx = word[i]-'a';
            score += crawler->child[ch_idx]->countp;
            
            crawler = crawler->child[ch_idx];
        }

        return score;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();

        trieNode* root = getNode();

        for(int i = 0; i<n; i++) {
            insert(root, words[i]);
        }

        vector<int> result(n);
        for(int i = 0; i<n; i++) {
            result[i] = search(words[i], root);
        }

        return result;
    }
};
