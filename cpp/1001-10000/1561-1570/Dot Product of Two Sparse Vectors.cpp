class SparseVector {
public:
    
    vector<pair<int, int>> idx_value_pairs;
    
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) continue;
            
            idx_value_pairs.push_back({i, nums[i]});
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int i = 0, j = 0;
        int result = 0;
        
        while (i < idx_value_pairs.size() && j < vec.idx_value_pairs.size()) {
            if (idx_value_pairs[i].first < vec.idx_value_pairs[j].first) {
                i++;
            } else if (idx_value_pairs[i].first > vec.idx_value_pairs[j].first) {
                j++;
            } else {
                result += (idx_value_pairs[i].second * vec.idx_value_pairs[j].second);
                i++;
                j++;
            }
        }
        
        return result;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
