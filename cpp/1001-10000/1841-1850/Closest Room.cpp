class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<int> idx(m);
        std::iota(idx.begin(), idx.end(), 0);

        std::sort(idx.begin(), idx.end(), [&queries](int idx1, int idx2) {
            return queries[idx1][1] > queries[idx2][1];
        });
        std::sort(rooms.begin(), rooms.end(), [](const vector<int>& room1, const vector<int>& room2) {
            return room1[1] > room2[1];
        });
        
        vector<int> ans(m, -1);
        int room_idx = 0;
        set<int> valid_rooms;
        for (int e : idx) {
            int preferred = queries[e][0];
            int min_size = queries[e][1];
            
            while (room_idx < rooms.size() && rooms[room_idx][1] >= min_size) {
                valid_rooms.insert(rooms[room_idx][0]);
                room_idx++;
            }
            
            if (valid_rooms.empty()) {
                continue;
            }
            
            auto it = valid_rooms.upper_bound(preferred);
            if (it != valid_rooms.end()) {
                ans[e] = *it;
            }
            if (it != valid_rooms.begin()) {
                it--;
                if (ans[e] == -1) {
                    ans[e] = *it;
                } else if (preferred - *it <= ans[e] - preferred) {
                    ans[e] = *it;
                }
            }
        }
        
        return ans;
    }
};
