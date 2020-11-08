class Solution {
    
    vector<int> sums;
    
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    
    int query(int v_min, int v_max, int l, int r, int root) {
        if (v_min <= l && v_max >= r) {
            return sums[root];
        }
        if (v_min > r || v_max < l) {
            return 0;
        }
        
        int mid = (l+r)/2;
        return query(v_min, v_max, l, mid, left(root)) + query(v_min, v_max, mid+1, r, right(root));
    }
    
    void update(int v, int l, int r, int root) {
        if (v < l || v > r) {
            return;
        }
        
        sums[root]++;
        
        if (l == r) {
            return;
        }
        
        int mid = (l+r)/2;
        
        if (v <= mid) update(v, l, mid, left(root));
        else update(v, mid+1, r, right(root));
    }
    
public:
    int createSortedArray(vector<int>& instructions) {
        long mod = 1e9+7;
        long cost = 0;
        int N = *max_element(instructions.begin(), instructions.end()) + 1;
        sums.resize(4*N+4);
        
        for (int v : instructions) {
            int small = query(0, v-1, 0, N-1, 0);
            int great = query(v+1, 9999999, 0, N-1, 0);
            cost += min(small, great);
            cost %= mod;
            update(v, 0, N-1, 0);
        }
        
        return cost;
    }
};
