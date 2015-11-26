class Solution {
    
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> res;
        if(n <= 2) {
            for(int i = 0;i < n;i++)
                res.push_back(i);
            return res;
        }
        int k = 0;
        
        vector<set<int>> myvec(n, set<int>());
        queue<int> myqueue;
        
        for(auto e : edges) {
            myvec[e.first].insert(e.second);
            myvec[e.second].insert(e.first);
        }
        
        for(int i = 0;i < n;i++) {
            if(myvec[i].size() == 1) {
                myqueue.push(i);
                k++;
            }
        }
        
        while(1) {
            int j = myqueue.size();
            for(int i = 0;i < j;i++) {
                int v = myqueue.front();
                myqueue.pop();
                for(auto e : myvec[v]) {
                    myvec[e].erase(v);
                    if(myvec[e].size() == 1) {
                        myqueue.push(e);
                        k++;
                    }
                }
            }
            if(n == k) break;
        }
        
        while(!myqueue.empty()) {
            res.push_back(myqueue.front());
            myqueue.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};