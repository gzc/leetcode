class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        std::vector<int>::iterator low,up;
        low =std::lower_bound (nums.begin(), nums.end(), target);
        up = std::upper_bound (nums.begin(), nums.end(), target); 
        vector<int> result;
        if (low == up) {
            result.push_back(-1);
            result.push_back(-1);
        } else {
            result.push_back(low - nums.begin());
            result.push_back(up - nums.begin() - 1);
        }
        return result;
    }
};



class Solution {
    
    int FindFirst(const vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        
        int pos = -1;
        while (i <= j) {
            int mid = (i + j) / 2;
            
            if (nums[mid] == target) {
                pos = mid;
                j = mid - 1;
            } else if (nums[mid] > target) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        
        return pos;
    }
    
    int FindLast(const vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        
        int pos = -1;
        while (i <= j) {
            int mid = (i + j) / 2;
            
            if (nums[mid] == target) {
                pos = mid;
                i = mid + 1;
            } else if (nums[mid] > target) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        
        return pos;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans{FindFirst(nums, target), FindLast(nums, target)};
        return ans;
    }
};
