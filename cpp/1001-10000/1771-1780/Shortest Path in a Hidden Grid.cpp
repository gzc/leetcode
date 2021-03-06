/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *   public:
 *     bool canMove(char direction);
 *     void move(char direction);
 *     boolean isTarget();
 * };
 */

class Solution {
public:
    // 0 is blocked, 1 is empty, 2 is target
    void ConstructGrid(vector<vector<int>>& grid, GridMaster &master, int row, int col, const map<char, pair<int, int>>& directions) {
        grid[row][col] = 1;
        if (master.isTarget()) {
            grid[row][col] = 2;
        }
        
        for (const auto& direction : directions) {
            int new_row = row + direction.second.first;
            int new_col = col + direction.second.second;
            if (grid[new_row][new_col] != -1) {
                continue;
            }
            if (master.canMove(direction.first)) {
                master.move(direction.first);
                ConstructGrid(grid, master, new_row, new_col, directions);
                if (direction.first == 'U') master.move('D');
                else if (direction.first == 'D') master.move('U');
                else if (direction.first == 'L') master.move('R');
                else master.move('L');
            } else {
                grid[new_row][new_col] = 0;
            }
        }
    }
    
    int findShortestPath(GridMaster &master) {
        map<char, pair<int, int>> directions = {
            {'U', {0, 1}},
            {'D', {0, -1}},
            {'L', {-1, 0}},
            {'R', {1, 0}},
        };
        
        vector<vector<int>> grid(1001, vector<int>(1001, -1));
        ConstructGrid(grid, master, 501, 501, directions);
        
        queue<pair<int, int>> myqueue;
        myqueue.push({501, 501});
        grid[501][501] = 0;
        
        int distance = 1;
        while (!myqueue.empty()) {
            int queue_size = myqueue.size();
            for (int k = 0; k < queue_size; k++) {
                pair<int, int> cur = myqueue.front();
                myqueue.pop();
                
                for (const auto& direction : directions) {
                    int new_row = cur.first + direction.second.first;
                    int new_col = cur.second + direction.second.second;
                    if (grid[new_row][new_col] == 2) {
                        return distance;
                    }
                    if (grid[new_row][new_col] <= 0) {
                        continue;
                    }
                    // Mark as 'visited'.
                    grid[new_row][new_col] = 0;
                    myqueue.push({new_row, new_col});
                }
            }
            
            distance++;
        }
        
        return -1;
    }
};
