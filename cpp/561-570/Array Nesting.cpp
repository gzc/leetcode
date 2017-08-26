class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;
            int count = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = nums[j];
                count++;
            }
            result = max(result, count);
        }
        return result;
    }
};
