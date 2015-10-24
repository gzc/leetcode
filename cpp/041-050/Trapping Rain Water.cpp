class Solution {
public:
    int trap(vector<int>& height) {
        int result(0),i(0),j(height.size()-1);
        int maxleft(0), maxright(0);
        while(i < j)
        {
            if(height[i] <= height[j]) {
                if(height[i] > maxleft) maxleft = height[i];
                else result += (maxleft - height[i]);
                i++;
            } else {
                if(height[j] > maxright) maxright = height[j];
                else result += (maxright - height[j]);
                j--;
            }
        }
        return result;
    }
};