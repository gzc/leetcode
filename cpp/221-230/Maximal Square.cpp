class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        if(matrix.size() <= 0) return 0;
        
        vector<int> h(matrix[0].size()+1, 0);
        int res(0);
        
        for(int i = 0;i < matrix.size();i++)
        {
            stack<int> s;
            matrix[i].push_back('0');
            
            for(int j = 0;j < matrix[0].size();j++)
            {
                if(matrix[i][j] == '0') h[j] = 0;
                else h[j]++;
                
                if(s.empty() || h[j] >= h[s.top()])
                    s.push(j);
                
                else {
                    while(!s.empty() && h[j] < h[s.top()])
                    {
                        int tp = s.top();
                        s.pop();
                        int height = h[tp];
                        int width = (s.empty() ? j : j - s.top() - 1);

                        int side = min(height, width);
                        res = max(res, side*side);
                    }
                    s.push(j);
                }
            }
        }
        
        return res;
        
    }
    
    
};
