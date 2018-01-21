class Solution {
public:
    string reorganizeString(string S) {
        
        map<char, int> mymap;
        
        for (char ch : S) {
            mymap[ch]++;
            if (mymap[ch] > (S.length() + 1) / 2) return "";
        }
        
        auto cmp = [](const pair<int, char> &a, const pair<int, char> &b) {
            return a.first < b.first;
        };

        priority_queue<pair<int, char>, vector<pair<int, char>>, decltype(cmp)> pq(cmp);
        
        for (const auto& e : mymap) {
            pq.push({e.second, e.first});
        }
        
        string ans;
        while (!pq.empty()) {
            pair<int, char> first = pq.top();
            pq.pop();
            ans += first.second;
            if (!pq.empty()) {
                pair<int, char> second = pq.top();
                pq.pop();
                ans += second.second;
                if (first.first > 1) pq.push({first.first - 1, first.second});
                if (second.first > 1) pq.push({second.first - 1, second.second});
            }
        }
        return ans;
    }
};
