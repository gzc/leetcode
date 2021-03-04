class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector<double> result(cars.size(), -1.0);
        stack<int> mystack;
        
        for (int i = cars.size() - 1; i >= 0; i--) {
            // We don't need faster cars behind current car.
            while (!mystack.empty() && cars[i][1] <= cars[mystack.top()][1]) {
                mystack.pop();
            }
            
            while (!mystack.empty()) {
                int candidate = mystack.top();
                double current_time = 1.0 * (cars[candidate][0] - cars[i][0]) / (cars[i][1] - cars[candidate][1]);
                if (current_time <= result[candidate] || result[candidate] < 0) {
                    result[i] = current_time;
                    break;
                }
                // This car will collide with cars after candidate.
                mystack.pop();
            }
            
            mystack.push(i);
        }
        
        return result;
    }
};
