class Excel {
    vector<vector<int>> matrix;
    map<pair<int, int>, vector<string>> cellStrMapping;
    
    int c2i(char ch) { return ch - 'A'; }
    
    pair<int, char> parseNum(const string& num) {
        int row = stoi(num.substr(1));
        return {row, num[0]};
    }
public:
    Excel(int H, char W) {
        matrix = vector<vector<int>>(H, vector<int>(c2i(W) + 1, 0));
    }
    
    void set(int r, char c, int v) {
        int col = c2i(c);
        pair<int, int> mypair = {r, col};
        if (cellStrMapping.count(mypair) != 0) {
            cellStrMapping.erase(mypair);
        }
        matrix[r-1][c2i(c)] = v;
    }
    
    int get(int r, char c) {
        int col = c2i(c);
        pair<int, int> mypair = {r, col};
        if (cellStrMapping.count(mypair) == 0) {
            return matrix[r-1][col];
        } else {
            vector<string> allStrs = cellStrMapping[mypair];
            int result = 0;
            for (const string& num : allStrs) {
                int idx = num.find(':');
                if (idx >= 0) {
                    pair<int, char> cellStart = parseNum(num.substr(0, idx));
                    pair<int, char> cellEnd = parseNum(num.substr(idx + 1));
                    int row1 = cellStart.first;
                    int row2 = cellEnd.first;
                    int col1 = cellStart.second - 'A';
                    int col2 = cellEnd.second - 'A';
                    for (int i = row1; i <= row2; i++) {
                        for (int j = col1; j <= col2; j++) {
                            char ch = 'A' + j;
                            result += (get(i, ch));
                        }
                    }
                } else {
                    pair<int, char> cell = parseNum(num);
                    result += get(cell.first, cell.second);
                }
            }
            return result;
        }
    }
    
    int sum(int r, char c, vector<string> strs) {
        int col = c2i(c);
        pair<int, int> mypair = {r, col};
        cellStrMapping[mypair] = strs;
        return get(r, c);
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel obj = new Excel(H, W);
 * obj.set(r,c,v);
 * int param_2 = obj.get(r,c);
 * int param_3 = obj.sum(r,c,strs);
 */
