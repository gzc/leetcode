class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if(envelopes.size() < 2) return envelopes.size();
        auto Cmp = [](const pair<int, int> &a, const pair<int, int> &b) { 
            if(a.first < b.first) return true;
            if(a.first == b.first && a.second <= b.second) return true;
            return false;
        };
        sort(envelopes.begin(), envelopes.end(), Cmp);
        vector<int> myvec(envelopes.size(), 1);
        
        for(int i = 1;i < envelopes.size();i++) {
            for(int j = 0;j < i;j++) {
                if(envelopes[j].first < envelopes[i].first && envelopes[j].second < envelopes[i].second) {
                    myvec[i] = max(myvec[i], myvec[j]+1);
                }
            }
        }
        return *max_element(myvec.begin(),myvec.end());
    }
};
