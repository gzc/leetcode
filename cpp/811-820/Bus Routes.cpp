class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        unordered_map<int, unordered_set<int>> to_routes;
        for (int i = 0; i < routes.size(); ++i) for (auto& j : routes[i]) to_routes[j].insert(i);
        queue<pair<int, int>> bfs;
        bfs.push(make_pair(S, 0));
        unordered_set<int> seen = {S};
        while (!bfs.empty()) {
            int stop = bfs.front().first;
            int bus = bfs.front().second;
            bfs.pop();
            if (stop == T) return bus;
            for (const auto& route_i : to_routes[stop])
                for (int next_stop : routes[route_i])
                    if (seen.find(next_stop) == seen.end()) {
                        seen.insert(next_stop);
                        bfs.push(make_pair(next_stop, bus + 1));
                    }
        }
        return -1;
    }
};
