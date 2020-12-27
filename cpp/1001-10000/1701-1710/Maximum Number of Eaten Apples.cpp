class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        auto cmp = [](const pair<int, int>& l, const pair<int, int>& r) {
            return l.first > r.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        
        int n = apples.size();
        int ans = 0;
        
        int i = 0;
        for (; i < n; i++) {
            
            if (apples[i] > 0) {
                pq.push({i+days[i], apples[i]});
            }
            
            while (!pq.empty()) {
                pair<int, int> ele = pq.top();
                pq.pop();

                if (ele.first > i) {
                    ans++;
                    ele.second--;
                    if (ele.second > 0) {
                        pq.push(ele);
                    }
                    break;
                }
            }
        }
        
        while (!pq.empty()) {
            pair<int, int> ele = pq.top();
            pq.pop();

            if (ele.first > i) {
                ans++;
                ele.second--;
                if (ele.second > 0) {
                    pq.push(ele);
                }
                
                i++;
            }
        }
        
        return ans;
    }
};
