class Solution {
    
    int MatchGroup(const vector<int>& group, const vector<int>& nums,  int index) {
        for (int start = index; start <= nums.size() - group.size(); start++) {
            bool match = true;
            for (int l = 0; l < group.size(); l++) {
                if (group[l] != nums[start+l]) {
                    match = false;
                    break;
                }
            }
            
            if (match) {
                return start + group.size();
            }
        }
        
        return -1;
    }
    
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int index = 0;
        for (const vector<int>& group : groups) {
            index = MatchGroup(group, nums, index);
            if (index < 0) {
                return false;
            }
        }
        return true;
    }
};
