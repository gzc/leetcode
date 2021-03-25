/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
    
    void dfs(Robot &robot, set<pair<int, int>>& visited, int i, int j, int dir) {
        pair<int, int> directions[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        robot.clean();
        visited.insert({i, j});
        for (int k = 0; k < 4; k++) {
            int new_i = i + directions[dir].first;
            int new_j = j + directions[dir].second;
            if (visited.count({new_i, new_j}) == 0 && robot.move()) {
                dfs(robot, visited, new_i, new_j, dir);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
            }
            dir = (dir + 1) % 4;
            robot.turnRight();
        }
    }
    
public:
    void cleanRoom(Robot& robot) {
        set<pair<int, int>> visited;
        dfs(robot, visited, 0, 0, 0);
    }
};
