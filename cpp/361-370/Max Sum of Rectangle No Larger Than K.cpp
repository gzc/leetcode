class Solution {
    
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int res(INT_MIN);
        
        for(int col1 = 0; col1 < cols;col1++) {
            
            vector<int> vec(rows, 0);
            
            for(int col2 = col1;  col2 < cols;col2++) {
                
                for(int k = 0;k < rows;k++) {
                    vec[k] += matrix[k][col2];
                }
                
                set<int> cumset;
                cumset.insert(0);
                int best=INT_MIN, cum=0;
                for(int i = 0;i < rows;i++)
                {
                    cum+=vec[i];
                    set<int>::iterator sit=cumset.lower_bound(cum-k);
                    if(sit!=cumset.end())best=max(best,cum-*sit);
                    cumset.insert(cum);
                }
                res = max(res, best);
            }
        }
        
        return res;
    }
};
