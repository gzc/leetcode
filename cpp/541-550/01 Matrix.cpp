class Solution {
    
    struct point {
        int i;
        int j;
        int d;
        point (int _i, int _j, int _d): i(_i), j(_j), d(_d) { }
    };
    
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();
        vector<vector<int>> result(row, vector<int>(column, -1));
        queue<point> myqueue;
        vector<pair<int, int>> pos{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (matrix[i][j] == 0) {
                    result[i][j] = 0;
                    myqueue.emplace(point(i, j, 0));
                }
            }
        }
        
        while (!myqueue.empty()) {
            point current = myqueue.front();
            myqueue.pop();
            for (const auto& e : pos) {
                int nexti = current.i + e.first;
                int nextj = current.j + e.second;
                if (nexti < 0 || nexti >= row || nextj < 0 || nextj >= column) continue;
                if (result[nexti][nextj] < 0) {
                    if (result[nexti][nextj] < 0) {
                        result[nexti][nextj] = current.d + 1;
                        myqueue.push(point(nexti, nextj, current.d + 1));
                    }
                }
            }
        }
        
        return result;
    }
};
