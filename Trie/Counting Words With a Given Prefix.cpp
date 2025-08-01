//Approach-1 Brute Force
//T.C : O(n^m), where n = number of words, m = length of pref
//S.C : O(n^m)
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (string& word : words) {
            if (word.find(pref) == 0) {
                count++;
            }
        }
        return count;
    }
};


//Approach-2 (Using Trie)
//T.C : O(n^l + m), where n = number of words, m = length of pref, l = average length of word
//S.C : O(n^l)
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
            newNode->child[i] = nullptr;
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

            crawler->child[ch_idx]->countp++; //Count increased for prefix ending at this character node
            crawler = crawler->child[ch_idx];
        }
    }

    int search(trieNode* root, string word) {
        trieNode* crawler = root;

        for(int i = 0; i<word.size(); i++) {
            int ch_idx = word[i]-'a';

            if(crawler->child[ch_idx] == NULL) {
                return 0;
            }

            crawler = crawler->child[ch_idx];
        }

        return crawler->countp; //count of prefix ending at the last character of pref wala node

    }

    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();

        trieNode* root = getNode();

        for(int i = 0; i<n; i++) {
            insert(root, words[i]);
        }

        return search(root, pref);
    }
};
