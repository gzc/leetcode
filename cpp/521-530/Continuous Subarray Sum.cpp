class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;
        long K = abs(long(k));
        map<int, int> record;
        record[0] = -1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] + nums[i] == 0) {
                return true;
            }
        }
        
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int e = nums[i];
            sum += e;
            if (sum == 0 && e != 0) return true;
            if (k == 0) continue;
            // Make it a positive number to avoid bad mod.
            if (sum < 0) sum += (-1*sum / K) * K + K;
            int target = sum % K;
            // You can also remove following line.
            sum = target;
            if (record.count(target) > 0) {
                if (i - record[target] > 1) return true;
            } else {
                record[target] = i;
            }
        }
        return false;
    }
};
