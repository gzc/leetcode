class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        map<char, vector<int>> mymap;
        int len = S.length();
        for (int i = 0; i < len; i++) {
            mymap[S[i]].push_back(i);
        }
        
        int ans = 0;
        for (const string& word : words) {
            int cur = 0;
            bool found = true;
            for (char ch : word) {
                const vector<int>& temp = mymap[ch];
                auto it = lower_bound(temp.begin(), temp.end(), cur);
                if (it == temp.end()) {
                    found = false;
                    break;
                }
                cur = *it;
                cur++;
            }
            if (found) ans++;
        }
        
        return ans;
    }
};
