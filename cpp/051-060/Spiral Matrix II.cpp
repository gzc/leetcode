#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        
        vector<vector <int> > result(n ,vector<int>(n));
        
        if(n == 0)
            return result;
        
        int h = n;
        int w = n;
        int step = 1;
        int i(0),j(0);
        int z = 1;
        
        while(w > 0 && h > 0)
        {
            for(int k = 0;k < w;k++)
            {
                result[i][j] = z++;
                j += step;
            }
            j -= step;
            i += step;
            
            h--;
            for(int k = 0;k < h;k++)
            {
                result[i][j] = z++;
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