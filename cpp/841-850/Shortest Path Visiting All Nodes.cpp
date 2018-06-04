class Solution {
    
    int getKey(const pair<int, set<int>>& e) {
        long key = e.first << 20;;
        
        for (int i = 0; i < 12; i++) {
            if (e.second.count(i) > 0) {
                key = key | (1 << i);
            }
        }
        
        return key;
    }
    
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n = graph.size();
        int ans = INT_MAX;
        unordered_map<int, int> cache;
        
        for (int i = 0; i < n; i++) {
            set<int> unvisited;
            
            for (int k = 0; k < n; k++) {
                if (k != i) unvisited.insert(k);
            }
            queue<pair<int, set<int>>> myqueue;
            myqueue.push(make_pair(i, unvisited));
            int key = getKey(make_pair(i, unvisited));
            cache[key] = 0;
            
            while (!myqueue.empty()) {
                pair<int, set<int>> cur = myqueue.front();
                myqueue.pop();
                int key = getKey(cur);
                
                if (cur.second.empty()) {
                    ans = min(ans, cache[key]);
                    break;
                }
                
                int step = cache[key];
                
                for (int v : graph[cur.first]) {
                    set<int> newUnvisited = (cur.second);
                    newUnvisited.erase(v);
                    pair<int, set<int>> newPair = make_pair(v, newUnvisited);
                    int nkey = getKey(newPair);
                    if (cache.count(nkey) > 0 && (cache[nkey] <= step + 1)) continue;
                    cache[nkey] = step+1;
                    myqueue.emplace(newPair);
                }
            }
        }
        
        return ans;
    }
};
