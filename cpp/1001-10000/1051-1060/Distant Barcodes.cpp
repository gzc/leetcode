class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second < b.second || (a.second == b.second && a.first > b.first);
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        
        map<int, int> mymap;
        for (int e : barcodes) {
            mymap[e]++;
        }
        
        for (auto it : mymap) {
            pq.push(it);
        }
        
        vector<int> ans;
        while (!pq.empty()) {
            pair<int, int> e1 = pq.top();
            pq.pop();
            ans.push_back(e1.first);
            if (!pq.empty()) {
                pair<int, int> e2 = pq.top();
                pq.pop();
                ans.push_back(e2.first);
                if (e2.second > 1) {
                    pq.push({e2.first, e2.second - 1});
                }
            }
            if (e1.second > 1) {
                pq.push({e1.first, e1.second - 1});
            }
        }
        
        return ans;
    }
};
