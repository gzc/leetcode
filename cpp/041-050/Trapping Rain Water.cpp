class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int maxleft = 0, maxright = 0;
        int res = 0;
        while(i < j) {
            if(height[i] <= height[j]) {
                if (height[i] > maxleft) maxleft = height[i];
                else res += (maxleft - height[i]);
                i++;
            } else {
                if (height[j] > maxright) maxright = height[j];
                else res += (maxright - height[j]);
                j--;
            }
        }
        return res;
    }
};
