class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int result = 0;
        int temp_max = arr[0];
        for (int i = 0; i < arr.size(); i++) {
            temp_max = max(temp_max, arr[i]);
            if (temp_max == i) {
                result++;
            }
        }
        
        return result;
    }
};
