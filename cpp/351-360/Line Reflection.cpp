class Solution {
    
    set<pair<int, int>> myset;
    
public:
    bool isReflected(vector<pair<int, int>>& points) {
        
        int small(INT_MAX);
        int large(INT_MIN);
        
        for(auto e : points) {
            small = min(small, e.first);
            large = max(large, e.first);
            myset.insert(e);
        }
        
        int mid2 = small+large;
        
        for(auto e : points) {
            pair<int, int> ref = make_pair(mid2 - e.first, e.second);
            if(myset.count(ref) == 0) return false;
        }
        return true;
    }
};
