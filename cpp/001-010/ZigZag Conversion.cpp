class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        
        vector<string> rows(numRows);
        int row = 0;
        int step = 1;
        for (char ch : s) {
            rows[row].push_back(ch);
            
            if (row == (numRows - 1)) {
                step = -1;
            } else if (row == 0) {
                step = 1;
            }
            row += step;
        }
        
        stringstream ss;
        for (const string& row : rows) {
            ss << row;
        }
        return ss.str();
    }
};
