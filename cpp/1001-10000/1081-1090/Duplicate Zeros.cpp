class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int zeros_now = 0;
        for (int e : arr) {
            zeros_now += (e == 0);
        }
        
        int n = arr.size();
        
        for (int i = arr.size()-1; i >= 0; i--) {
            if (arr[i] != 0) {
                int pos = i + zeros_now;
                int copy = arr[i];
                arr[i] = 0;
                if (pos < n) {
                    arr[pos] = copy;
                }
            } else {
                zeros_now--;
            }
        }
    }
};
