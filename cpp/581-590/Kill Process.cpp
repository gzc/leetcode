class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        map<int, vector<int>> ppids;
        for (int i = 0; i < pid.size(); i++) {
            ppids[ppid[i]].push_back(pid[i]);
        }
        
        vector<int> results;
        queue<int> myqueue;
        myqueue.push(kill);
        while (!myqueue.empty()) {
            int id = myqueue.front();
            myqueue.pop();
            results.push_back(id);
            if (ppids.count(id) > 0) {
                vector<int> ids = ppids[id];
                for (int e : ids) myqueue.push(e);
            }
        }
        
        return results;
    }
};
