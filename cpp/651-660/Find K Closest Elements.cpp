class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second > b.second || (a.second == b.second && a.first > b.first);
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        
        for (int e : arr) {
            int v = abs(e - x);
            pq.push({e, v});
        }
        
        vector<int> res;
        for (int i = 0; i < k; i++) {
            pair<int, int> e = pq.top();
            pq.pop();
            res.push_back(e.first);
        }
        sort(res.begin(), res.end());
        return res;
    }
};
