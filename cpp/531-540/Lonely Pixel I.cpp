class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int ans = 0;
        map<int, int> col, row;
        for (int i = 0; i < picture.size(); i++) {
            for (int j = 0; j < picture[0].size(); j++) {
                if (picture[i][j] == 'B') {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        
        for (int i = 0; i < picture.size(); i++) {
            for (int j = 0; j < picture[0].size(); j++) {
                if (picture[i][j] == 'B' && row[i] == 1 && col[j] == 1) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
