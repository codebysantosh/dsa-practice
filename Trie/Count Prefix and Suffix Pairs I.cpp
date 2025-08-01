//Approach-1 Brute Force
//T.C : O(n^2 * l)
//S.C : O(n^2 * l)
class Solution {
public:
    bool isPrefixAndSuffix(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        return s2.find(s1) == 0 && s2.rfind(s1) == n-m; 
        // return (s1 == s2.substr(0, m) && s1 == s2.substr(n-m, m));
    } 

    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();

        int count = 0;
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                if(words[i].size() <= words[j].size() && isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }

        return count;
    }
};


//Approach-2 - Using TRIE 
//T.C : ~O(n^2*l), n = number of words, l = average length of each word
//S.C : ~O(n*l), need to store all characters of words
struct trieNode {
    trieNode* child[26];
};

trieNode* getNode() {
    trieNode* newNode = new trieNode();

    for(int i = 0; i<26; i++) {
        newNode->child[i] = nullptr;
    }

    return newNode;
}

class Trie {
    public:
    trieNode* root;

    Trie() {
        root = getNode();
    }

    void insert(string word) {
        trieNode* crawler = root;

        for(int i = 0; i<word.size(); i++) {
            int ch_idx = word[i]-'a';

            if(crawler->child[ch_idx] == nullptr) {
                crawler->child[ch_idx] = getNode();
            }

            crawler = crawler->child[ch_idx];
        }
    } 

    bool search(string word) {
        trieNode* crawler = root;

        for(int i = 0; i<word.size(); i++) {
            int ch_idx = word[i]-'a';

            if(crawler->child[ch_idx] == NULL) {
                return false;
            }

            crawler = crawler->child[ch_idx];
        }

        return true;
    }
};

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        
        int count = 0;

        for(int i = 0; i<n; i++) {
            Trie prefixTrie;
            Trie suffixTrie;

            prefixTrie.insert(words[i]);
            string reversed = words[i];
            reverse(begin(reversed), end(reversed));
            suffixTrie.insert(reversed);

            for(int j = 0; j<i; j++) {
                if(words[j].size() > words[i].size()) continue;

                string rev = words[j];
                reverse(begin(rev), end(rev));

                if(prefixTrie.search(words[j]) == true && suffixTrie.search(rev) == true) {
                    count++;
                }
            }
        }

        return count;
    }
};
