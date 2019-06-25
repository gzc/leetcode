/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
    
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int left = 0;
        int right = mountainArr.length() - 1;
        
        while (left <= right) {
            
            if (right - left < 6) {
                for (int k = left; k <= right; k++) {
                    if (mountainArr.get(k) == target) return k;
                }
                return -1;
            }
            
            int mid = (left+right)/2;
            int nmid = mid+1;
            
            int v = mountainArr.get(mid);
            if (v == target) return mid;
            int vv = mountainArr.get(nmid);
            if (vv == target) return nmid;
            
            bool isup = vv > v;
            
            if (isup) {
                // [left, mid - 1]
                if (target < v) {
                    
                    int l = left;
                    int r = mid - 1;
                    
                    while (r - l >= 2) {
                        int mid_ = (l+r)/2;
                        int v_ = mountainArr.get(mid_);
                        if (v_ == target) return mid_;
                        if (v_ < target) l = mid_ + 1;
                        else r = mid_ - 1;
                    }
                    
                    while (l <= r) {
                        if (mountainArr.get(l) == target) return l;
                        l++;
                    }
                    
                }
                left = nmid + 1;
            } else {
                // [mid+1, right]
                if (target < vv) {
                    
                    int l = mid+1;
                    int r = right;
                    
                    while (r - l >= 2) {
                        int mid_ = (l+r)/2;
                        int v_ = mountainArr.get(mid_);
                        if (v_ == target) return mid_;
                        if (v_ > target) l = mid_ + 1;
                        else r = mid_ - 1;
                    }
                    
                    while (l <= r) {
                        if (mountainArr.get(l) == target) return l;
                        l++;
                    }
                    
                }
                right = mid - 1;
            }
        }
        return -1;
    }
};
