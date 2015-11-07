class Solution {
    
    int top;
    int left;
    int right;
    int bottom;
    
    pair<int, int> pos[4] = {
        {-1,0},{1,0},{0,-1},{0,1}
    };
    
    void bfs(vector<vector<char>>& image, int x, int y) {
        
        image[x][y] = '0';
        
        left = min(left, y);
        right = max(right, y);
        top = min(top, x);
        bottom = max(bottom, x);
        
        for(auto e : pos) {
            int nx = x + e.first;
            int ny = y + e.second;
            if(nx >= 0 && nx < image.size() && ny >= 0 && ny < image[0].size() && image[nx][ny] == '1')
                bfs(image, nx, ny);
        }
    }
    
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        
        top = bottom = x;
        left = right = y;
        
        bfs(image, x, y);
        
        int res = (right - left + 1) * (bottom - top + 1);
        return res;
    }
};