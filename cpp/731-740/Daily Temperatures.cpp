class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> mystack;

        for (int i = 0; i < temperatures.size(); i++) {
            while (!mystack.empty() && mystack.top().first < temperatures[i]) {
                res[mystack.top().second] = i - mystack.top().second;
                mystack.pop();
            }
            mystack.push({temperatures[i], i});
        }

        return res;
    }
};
