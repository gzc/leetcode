class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size());
        
        stack<pair<int, int>> mystack; // day, temp
        
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            int currentTemp = temperatures[i];
            int day = -1;
            while (!mystack.empty()) {
                if (currentTemp >= mystack.top().second) {
                    mystack.pop();
                } else {
                    day = mystack.top().first;
                    mystack.push({i, currentTemp});
                    break;
                }
            }
            if (mystack.empty()) {
                mystack.push({i, currentTemp});
            }
            result[i] = day == -1 ? 0 : day - i;
        }
        
        return result;
    }
};
