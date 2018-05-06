class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> ans;
        
        for (int i = 0; i < S.size(); ++i) {
            int begin = i;
            int count = 1;
            
            while (i + 1 < S.size() && S[i] == S[i + 1]) ++i, ++count;
            
            if (count >= 3)
                ans.push_back({begin, begin + count - 1});
        }
        return ans;
    }
};
