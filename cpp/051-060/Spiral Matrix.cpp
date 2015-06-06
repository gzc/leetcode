#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        
        vector<int>result;
        
        if(matrix.size() == 0)
            return result;
        
        int h = matrix.size();
        int w = matrix[0].size();
        int step = 1;
        int i(0),j(0);
        
        while(w > 0 && h > 0)
        {
            for(int k = 0;k < w;k++)
            {
                result.push_back(matrix[i][j]);
                j += step;
            }
            j -= step;
            i += step;
            
            h--;
            for(int k = 0;k < h;k++)
            {
                result.push_back(matrix[i][j]);
                i += step;
            }
            i -= step;
            
            step *= -1;
            
            j += step;
            
            w--;
        }
        return result;
    }
    
};

int main()
{
    Solution s;
    
    return 0;
}