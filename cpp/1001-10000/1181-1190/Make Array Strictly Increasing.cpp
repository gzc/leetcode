class Solution {
    map<pair<int, int>, int> cache;
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        int val= dfs(arr1, arr2, 0, -1);
        if(val>=2000)
            return -1;
        else
            return val;
    }
    
    int dfs(vector<int>& arr1, vector<int>& arr2, int i, int prev) {
        if (i >= arr1.size()) return 0;
        pair<int, int> key = {i, prev};
        if (cache.count(key) > 0) return cache[key];
        
        // find the next greater element in arr2 than prev
        auto it = upper_bound(arr2.begin(), arr2.end(), prev);
        int j = it - arr2.begin();
        
        int val;
        if (arr1[i] <= prev) {
            // Current value is not valid.
            if (j >= arr2.size()) {
                // we cannot find any value in arr2 to replace
                val = 2500;
            } else {
                val = 1 + dfs(arr1, arr2, i+1, arr2[j]);   
            }
        } else {
            // Current value in arr1 is ok.
            // If we cannot make use of arr2 or arr1[i] is smaller than arr2[j](greedy).
            if (j >= arr2.size() || arr1[i] <= arr2[j]) {
                val = dfs(arr1, arr2, i+1, arr1[i]);
            } else {
                val = min(dfs(arr1, arr2, i+1, arr1[i]), 1+dfs(arr1, arr2, i+1, arr2[j]));
            }
        }
        
        return cache[key] = val;
    }
    
};
