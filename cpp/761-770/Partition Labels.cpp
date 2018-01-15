class Solution {
public:
    vector<int> partitionLabels(string S) {
        map<char, int> mymap;
        for (int i = 0; i < S.length(); i++) {
            mymap[S[i]] = i;
        }
        
        vector<int> ans;
        int maximum_pos = 0;
        int last = -1;
        for (int i = 0; i < S.length(); i++) {
            char ch = S[i];
            maximum_pos = max(maximum_pos, mymap[ch]);
            if (i == maximum_pos) {
                ans.push_back(i - last);
                last = i;
            }
        }
        
        return ans;
    }
};
