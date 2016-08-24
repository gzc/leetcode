class Solution {
    
    void help(vector<vector<int>>& result, int begin, vector<int> num) {
        if (begin == num.size()) {
            result.emplace_back(num);
            return;
        }
 
        for (int i = begin; i < num.size();i++) {
            if (i != begin && num[i] == num[begin]) continue;
            swap(num[begin], num[i]);
            help(result, begin+1, num);
        }
    }
    
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int>> result;
        sort(num.begin(), num.end());
        help(result, 0, num);
        return result;
    }
};
