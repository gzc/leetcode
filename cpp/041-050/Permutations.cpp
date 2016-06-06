class Solution {
    
    void help(vector<vector<int>>& result, int begin, vector<int> &num)
    {
        if(begin == num.size()) {
            result.push_back(num);
            return;
        }
            
        for(int i = begin; i < num.size();i++)
        {
            swap(num[begin], num[i]);
            help(result, begin+1, num);
            swap(num[begin], num[i]);
        }
    }
    
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> result;
        help(result, 0, num);
        return result;
    }
};
