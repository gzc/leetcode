class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        
        sort(S.begin(),S.end());
        vector<vector<int>> sets;
        vector<int> empty;
        sets.push_back(empty);
        int num = 1;
        for(int i = 0;i < S.size();i++)
        {
            for(int k = 0;k < num;k++)
            {
                vector<int> tmp = sets[k];
                tmp.push_back(S[i]);
                sets.push_back(tmp);
            }
            num *= 2;
        }
        return sets;
    }
};
