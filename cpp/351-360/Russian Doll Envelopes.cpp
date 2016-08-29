class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        auto Cmp = [&](const pair<int, int> a, const pair<int, int> b) { 
            if(a.first < b.first) return true;
            if(a.first == b.first && a.second > b.second) return true;
            return false;
        };
        auto Cmp2 = [&](const pair<int, int> a, const pair<int, int> b) { 
            return a.second < b.second;
        };
        sort(envelopes.begin(), envelopes.end(), Cmp);

        vector<pair<int, int>> res;
        for (int i=0; i<envelopes.size(); i++) {
            auto it = std::lower_bound(res.begin(), res.end(), envelopes[i], Cmp2);
            if (it == res.end()) res.push_back(envelopes[i]);
            else *it = envelopes[i];
        }
        return res.size();
    }
};
