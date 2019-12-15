class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string tmp = "123456789";
        
        vector<int> res;
        for (int i = 0; i < 9; i++) {
            for (int j = i+1; j <= 9; j++) {
                int len = j - i;
                string str = tmp.substr(i, len);
                int v = stol(str);
                if (v >= low && v <= high) res.push_back(v);
            }
        }
        
        sort(res.begin(), res.end());
        return res;
    }
};
