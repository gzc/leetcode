/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *   public:
 *     bool canMove(char direction);
 *     int move(char direction);
 *     boolean isTarget();
 * };
 */

class Solution {
    pair<int, int> target;
public:
    // 0 is blocked
    void ConstructGrid(vector<vector<int>>& grid, GridMaster &master, int row, int col, const map<char, pair<int, int>>& directions, int cost) {
        grid[row][col] = cost;
        if (master.isTarget()) {
            target.first = row;
            target.second = col;
        }
        
        for (const auto& direction : directions) {
            int new_row = row + direction.second.first;
            int new_col = col + direction.second.second;
            if (grid[new_row][new_col] != -1) {
                continue;
            }
            if (master.canMove(direction.first)) {
                int cost = master.move(direction.first);
                ConstructGrid(grid, master, new_row, new_col, directions, cost);
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
            {'U', {-1, 0}},
            {'D', {1, 0}},
            {'L', {0, -1}},
            {'R', {0, 1}},
        };
        
        vector<vector<int>> grid(300, vector<int>(300, -1));
        ConstructGrid(grid, master, 150, 150, directions, /*cost=*/1);
        
        auto cmp = [](const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) {
            return a.second > b.second;
        };
        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, decltype(cmp)> myqueue(cmp);
        myqueue.push({{150, 150}, 0});
        // mark as visited.
        grid[150][150] = -1;
        
        while (!myqueue.empty()) {
            pair<pair<int, int>, int> cur = myqueue.top();
            myqueue.pop();
            
            if (cur.first == target) {
                return cur.second;
            }
            int r = cur.first.first;
            int c = cur.first.second;
            grid[r][c] = -1;
            
            for (auto& [ch, direction] : directions) {
                int new_row = r + direction.first;
                int new_col = c + direction.second;
                if (grid[new_row][new_col] <= 0) {
                    continue;
                }
                myqueue.push({{new_row, new_col}, cur.second + grid[new_row][new_col]});
            }
        }
        
        return -1;
    }
};
