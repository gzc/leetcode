class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        
        unordered_map<int, int> mymap;
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                mymap[nums[i] * nums[j]]++;
            }
        }
        
        int ans = 0;
        for (const auto& pair : mymap) {
            if (pair.second > 1) {
                int v = pair.second;
                int tmp = v * (v-1) * 4;
                ans += tmp;
            }
        }
        
        return ans;
    }
};
