class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int row = A.size();
        int col = A[0].size();
        int c, r;
        
        // find the first '1' (i.e. the first island) by scaning the matrix
        for (int i = 0; i < row * col; i++) {
            c = i % col;
            r = i / col;
            if (A[r][c] == 1)
                break;
        }

        queue<pair<int,int>> q1,q2;
        q1.push({r,c});
        A[r][c] = -1;
        
        int d[][2] = {{-1,0}, {0,1}, {1,0}, {0, -1}};
        while (!q1.empty()) {
            auto cur = q1.front();
            q1.pop();
            for (int i = 0; i < 4; i++) {
                int newr = cur.first + d[i][0];
                int newc = cur.second + d[i][1];
                
                if (newr < 0 || newc < 0 || newr >= row || newc >= col) continue;
                
                if (A[newr][newc] == 1) {
                    A[newr][newc] = -1;
                    q1.push({newr, newc});
                } else if (A[newr][newc] == 0) {
                    A[newr][newc] = -1;
                    q2.push({newr, newc});
                }
            }
        }
             
        int step = 0;
        while (!q2.empty()) {
            auto size = q2.size();
            step++;
            for (int j = 0; j < size; j++) {
                auto cur = q2.front();
                q2.pop();
                for (int i = 0; i < 4; i++) {
                    int newr = cur.first + d[i][0];
                    int newc = cur.second + d[i][1];

                    if (newr < 0 || newc < 0 || newr >= row || newc >= col) continue;
                    
                    if (A[newr][newc] == -1) continue;
                    
                    if (A[newr][newc] == 1) return step;

                    q2.push({newr, newc});
                    A[newr][newc] = -1;
                }
            }            
        }
    }
};
