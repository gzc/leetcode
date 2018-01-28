class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        map<int, set<vector<int>>> mymap;
        for (const vector<int>& time : times) {
            mymap[time[0]].insert(time);
        }
        
        vector<int> dist(N+1, INT_MAX);
        dist[K] = 0;
        
        auto cmp = [](const vector<int> &a, const vector<int> &b) {
            return a[2] >= b[2];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for (const vector<int>& time : mymap[K]) {
            pq.push(time);
        }
        
        int ans = 0;
        int visited = 1;
        while (!pq.empty()) {
            vector<int> cur = pq.top();
            pq.pop();
            int src = cur[0];
            int dest = cur[1];
            if (dist[dest] != INT_MAX) continue;
            else {
                dist[dest] = cur[2];
                ans = max(ans, dist[dest]);
                visited++;
                for (vector<int> time : mymap[dest]) {
                    time[2] += dist[dest];
                    pq.push(time);
                }
            }
        }
        
        return visited == N ? ans : -1;
    }
};
