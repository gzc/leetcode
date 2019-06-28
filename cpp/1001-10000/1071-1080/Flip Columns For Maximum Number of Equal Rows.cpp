class Solution {
    
    void process(map<string, int>& mymap, const vector<int>& vec) {
        string str1, str2;
        for (int e : vec) {
            str1 += ('0' + e);
            str2 += ('0' + (1-e));
        }
        mymap[str1]++;
        mymap[str2]++;
    }
    
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<string, int> mymap;
        
        for (const vector<int>& vec : matrix) {
            process(mymap, vec);
        }
        
        int ans = 0;
        for (auto e : mymap) {
            ans = max(ans, e.second);
        }
        return ans;
    }
};
