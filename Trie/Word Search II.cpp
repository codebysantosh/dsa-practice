//Approach-1 (Using string in struct)
class Solution {
public:
    
    struct trieNode {
        bool isEndOfWord;
        string word;
        trieNode* children[26];
    };
    
    trieNode* getNode() {
        trieNode* newNode = new trieNode();

        newNode->isEndOfWord = false;
        newNode->word = "";

        for(int i = 0; i<26; i++) {
            newNode->children[i] = NULL;
        }

        return newNode;
    }

    void insert(string word, trieNode* root) {
        trieNode* crawler = root;

        for(int i = 0; i<word.size(); i++) {
            if(crawler->children[word[i]-'a'] == NULL) {
                crawler->children[word[i]-'a'] = getNode();
            }    

            crawler = crawler->children[word[i]-'a'];
        }

        crawler->isEndOfWord = true;
        crawler->word = word;
    }

    vector<string> result;
    int m, n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void findTrieWord(int i, int j, vector<vector<char>>& board, trieNode* root) {
        if(i < 0 || i >= m || j < 0 || j >= n) {
            return;
        }

        if(board[i][j] == '$' || root->children[board[i][j] - 'a'] == NULL) {
            return;
        }

        root = root->children[board[i][j]-'a'];

        if(root->isEndOfWord == true) {
            result.push_back(root->word);
            root->isEndOfWord = false;
        }

        char temp = board[i][j];
        board[i][j] = '$'; //making visited

        for(auto &dir : directions) {
            int x = i + dir[0];
            int y = j + dir[1];

            findTrieWord(x, y, board, root);
        }

        board[i][j] = temp;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();

        trieNode* root = getNode();

        for(auto &w : words) {
            insert(w, root);
        }

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(root->children[board[i][j] - 'a'] != NULL) {
                    findTrieWord(i, j, board, root);
                }
            }
        }

        return result;
    }
};
