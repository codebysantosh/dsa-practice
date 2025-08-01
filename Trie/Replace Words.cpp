//Using Trie
//T.C : o(n*l + m*l) , n = number of words in the dictionary, m be the number of words in the sentence, and l be the average length of each word.
//S.C : O(n*l + m*l)
class Solution {
public:
    struct trieNode {
        bool endofword;
        trieNode* child[26];
    };

    trieNode* getNode() {
        trieNode* newNode = new trieNode();

        newNode->endofword = false;
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

            crawler = crawler->child[ch_idx];
        }

        crawler->endofword = true;
    }

    string search(string word, trieNode* root) {
        trieNode* crawler = root;

        for(int i = 0; i<word.size(); i++) {
            int ch_idx = word[i]-'a';

            if(crawler->child[ch_idx] == NULL) {
                return word;
            }

            crawler = crawler->child[ch_idx];

            if(crawler->endofword == true) { //shortest root of word
                return word.substr(0, i+1);
            }
        }

        return word; 
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        int n = dictionary.size();

        trieNode* root = getNode();

        for(int i = 0; i<n; i++) {
            insert(root, dictionary[i]);
        }

        stringstream ss(sentence);
        string word;
        string result;

        while(getline(ss, word, ' ')) {
            result += search(word, root) + " ";
        }

        result.pop_back();

        return result;
    }
};
