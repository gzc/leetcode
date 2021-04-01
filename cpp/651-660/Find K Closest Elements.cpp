// Solution 1.
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto it = lower_bound(arr.begin(), arr.end(), x);
        int idx = it - arr.begin();
        if (idx == arr.size()) {
            idx--;
        } else if (idx > 0) {
            if (abs(arr[idx - 1] - x) <= abs(arr[idx] - x)) {
                idx = idx - 1;
            }
        }
        
        int l = idx - 1;
        int r = idx + 1;
        for (int i = 2; i <= k; i++) {
            if (l < 0) {
                r++;
            } else if (r >= arr.size()) {
                l--;
            } else {
                if (abs(arr[l] - x) <= abs(arr[r] - x)) {
                    l--;
                } else {
                    r++;
                }
            }
        }
        
        return vector<int>(arr.begin() + l + 1, arr.begin() + r);
    }
};



// Solution 2.
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - k;
        
        while (left < right) {
            int mid = (left + right) / 2;
            
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};
