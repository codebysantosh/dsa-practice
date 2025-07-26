class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int i) {
        if(i == parent[i]) {
            return i;
        }

        return parent[i] = find(parent[i]);
    }

    void unioon(int x, int y) {

        int parent_x = find(x);
        int parent_y = find(y);

        if(parent_x == parent_y) {
            return;
        }

        if(rank[parent_x] > rank[parent_y]) {
            parent[parent_y] = parent_x;
        } else if(rank[parent_x] < rank[parent_y]) {
            parent[parent_x] = parent_y;
        } else {
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        parent.resize(26);
        rank.resize(26, 0);

        for(int i = 0; i<26; i++) {
            parent[i] = i;
        }

        for(auto &s : equations) {
            if(s[1] == '=') {
                unioon(s[0]-'a', s[3]-'a');
            }
        }

        for(auto &s : equations) {
            if(s[1] == '!') {
                if(find(s[0]-'a') == find(s[3]-'a')) {
                    return false;
                }
            }
        } 

        return true;
    }
};
