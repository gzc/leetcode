class Solution {
    vector<string> split(const string &s, char delim) {
        vector<string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }
    
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n, 0);
        stack<pair<int, int>> mystack; // pair<id, startTime>
        for (const string& log : logs) {
            vector<string> myvec = split(log, ':');
            int id = stoi(myvec[0]);
            bool flag = myvec[1] == "start" ? true : false; // true start; false end
            int time = stoi(myvec[2]);
            if (flag) {
                mystack.push({id, time});
            } else {
                pair<int, int> currentPair = mystack.top();
                mystack.pop();
                int timeSpent = time - currentPair.second + 1;
                result[currentPair.first] += timeSpent;
                if (!mystack.empty()) {
                    pair<int, int> callerPair = mystack.top();
                    result[callerPair.first] -= timeSpent;
                }
            }
        }
        return result;
    }
};
