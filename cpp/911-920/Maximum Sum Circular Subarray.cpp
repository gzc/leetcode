class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int sum = 0;
        int cur_max = 0;
        int max_so_far = INT_MIN;
        int cur_min = 0;
        int min_so_far = INT_MAX;
        
        for (int v : A) {
            cur_max = max(cur_max + v, v);
            max_so_far = max(max_so_far, cur_max);
            cur_min = min(cur_min + v, v);
            min_so_far = min(min_so_far, cur_min);
            
            sum += v;
        }
        
        if (max_so_far <= 0) return max_so_far;
        return max(max_so_far, sum - min_so_far);
    }
};
