class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        vector<pair<int, int>> myvec(values.size());
        for (int i = 0; i < values.size(); i++) {
            myvec[i] = make_pair(values[i], labels[i]);
        }
        
        sort(myvec.begin(), myvec.end());
        
        map<int, int> counts;
        int ans = 0;
        
        for (int i = myvec.size() - 1; i >= 0; i--) {
            if (num_wanted == 0) break;
            int label = myvec[i].second;
            if (counts[label] < use_limit) {
                counts[label]++;
                ans += myvec[i].first;
                num_wanted--;
            }
        }
        
        return ans;
    }
};
