//T.C = O(n + range)
//S.C = O(range)
class Solution {
  public:
    string countSort(string s) {
        int n = s.size();
        
        vector<int> freq(26, 0);
        
        for(int i = 0; i<n; i++) {
            int ch_idx = s[i]-'a';
            freq[ch_idx]++;
        }
        
        string result = "";
        for(int i = 0; i<26; i++) {
            while(freq[i]--) {
                result.push_back(i+'a');
            }
        }
        
        return result;
    }
};
