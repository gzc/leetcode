class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> dis(n, -1);
        dis[src] = 0;
        
        for (int i = 0; i <= K; i++) {
            vector<int> copy(dis);
            for (const vector<int>& flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int cost = flight[2];

                if (copy[u] < 0) continue;
                if (dis[v] < 0) dis[v] = copy[u] + cost;
                else dis[v] = min(dis[v], copy[u] + cost);
            }
        }
        
        return dis[dst];
    }
};
