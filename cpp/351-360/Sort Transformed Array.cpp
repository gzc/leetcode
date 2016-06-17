class Solution {
    
    int cal(int a, int b, int c, int x) {
        return a*x*x + b*x + c;
    }
    
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        
        vector<int> myvec;
        
        if(a == 0) {
            for(auto e : nums) {
                myvec.push_back(cal(a,b,c,e));
            }
            if(b < 0) reverse(myvec.begin(), myvec.end());
            return myvec;
        }
        
        float xx = b / (-2.0 * a);
        int pivot(0);
        for(int i = 0;i < nums.size();i++) {
            if(nums[i] >= xx) {
                pivot = i;
                break;
            }
        }
        
        int i(pivot-1), j(pivot);
        
        while(i >= 0 || j < nums.size()) {
            
            if(i < 0) {
                int x = nums[j];
                myvec.push_back(cal(a,b,c,x));
                j++;
            } else if(j >= nums.size()) {
                int x = nums[i];
                myvec.push_back(cal(a,b,c,x));
                i--;
            } else {
                int x1 = nums[i];
                int x2 = nums[j];
                if(abs(x1-xx) >= abs(x2-xx)) {
                    myvec.push_back(cal(a,b,c,x2));
                    j++;
                } else {
                    myvec.push_back(cal(a,b,c,x1));
                    i--;
                }
            }

        }
        
        if(a < 0) reverse(myvec.begin(), myvec.end());
        
        return myvec;
    }
};
