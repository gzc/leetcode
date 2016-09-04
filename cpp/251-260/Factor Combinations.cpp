class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> getFactors(int n) {
        getFHelp(n, 2, vector<int>());
        return res;
    }
    
    void getFHelp(int n, int bottom, vector<int> line) {
        for (int i = bottom; i<=sqrt(n); i++){
            if (n%i == 0) {
                vector<int> new_line(line);
                new_line.push_back(i);
                getFHelp(n/i, i, new_line);
                new_line.push_back(n/i);
                res.push_back(new_line);
            }
        }
    }
};
