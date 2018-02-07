class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        map<int, int> row, col;
        map<int, string> rowSig;
        for (int i = 0; i < picture.size(); i++) {
            string signature;
            for (int j = 0; j < picture[0].size(); j++) {
                signature = signature + picture[i][j];
                if (picture[i][j] == 'B') {
                    row[i]++;
                    col[j]++;
                }
            }
            rowSig[i] = signature;
        }
        
        int ans = 0;
        set<int> processed;
        for (int i = 0; i < picture.size(); i++) {
            for (int j = 0; j < picture[0].size(); j++) {
                if (picture[i][j] == 'B') {
                    if (row[i] != col[j]) continue;
                    if (row[i] != N) continue;
                    if (processed.count(j) > 0) continue;
                    string signature = rowSig[i];
                    
                    bool flag = true;
                    for (int k = 0; k < picture.size(); k++) {
                        if (picture[k][j] == 'B' && signature != rowSig[k]) {
                            flag = false;
                        }
                    }
                    if (flag) ans += N;
                    processed.insert(j);
                }   
            }
        }
        
        return ans;
    }
};
