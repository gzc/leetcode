class Solution {
    
    bool check(const vector<int>& nums, int maxOperations, int penalty) {
        int ops = 0;
        for (int num : nums) {
            ops += (num-1) / penalty;
        }
        return ops <= maxOperations;
    }
    
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        
        while (left < right) {
            int mid = (left + right) / 2;
            
            bool can_do_it = check(nums, maxOperations, mid);
            
            if (can_do_it) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};
