class RangeModule {
public:
   void addRange(int left, int right) {
        int n = invals.size();
        vector<pair<int, int>> tmp;
        for (int i = 0; i <= n; i++) {
            if (i == n || invals[i].first > right) {
                tmp.push_back({left, right});
                while (i < n) tmp.push_back(invals[i++]);
            }
            else if (invals[i].second < left) 
                tmp.push_back(invals[i]);
            else {
                left = min(left, invals[i].first);
                right = max(right, invals[i].second);
            }
        }
        invals = tmp;
    }
    
    bool queryRange(int left, int right) {
        int n = invals.size(), l = 0, r = n-1;
        while (l <= r) {
            int m = l+(r-l)/2;
            if (invals[m].first >= right)
                r = m-1;
            else if (invals[m].second <= left)
                l = m+1;
            else 
                return invals[m].first <= left && invals[m].second >= right;
        }
        return false;
    }
    
    void removeRange(int left, int right) {
        int n = invals.size();
        vector<pair<int, int>> tmp;
        for (int i = 0; i < n; i++) {
            if (invals[i].second <= left || invals[i].first >= right)
                tmp.push_back(invals[i]);
            else {
                if (invals[i].first < left)  tmp.push_back({invals[i].first, left});
                if (invals[i].second > right) tmp.push_back({right, invals[i].second});
            }
        }
        invals = tmp;
    }
private:
    vector<pair<int, int>> invals;
};
