//Just like Word Ladder
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end()); //fast access

        unordered_set<string> visited;

        queue<string> q;
        q.push(startGene);
        visited.insert(startGene);

        int level = 0;

        while(!q.empty()) {

            int N = q.size();

            while(N--) {

                string curr = q.front();
                q.pop();

                if(curr == endGene) {
                    return level;
                }

                for(auto &ch : "ACGT") {
                    for(int i = 0; i<curr.size(); i++) {
                        string nebour = curr;
                        nebour[i] = ch;

                        if(visited.find(nebour) == visited.end() && bankSet.find(nebour) != bankSet.end()) {
                            visited.insert(nebour);
                            q.push(nebour);
                        }
                    }
                }
            }

            level++;
        }

        return -1;
    }
};
