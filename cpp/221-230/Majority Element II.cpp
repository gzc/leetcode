class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n1,n2,c1(-1),c2(-1);
        vector<int>res;
        
        for(auto e : nums)
        {
            if(c1 < 0)
            {
                n1 = e;
                c1 = 1;
                continue;
            }
            
            if(c2 < 0 && e != n1)
            {
                n2 = e;
                c2 = 1;
                continue;
            }
            
            if(e == n1) c1++;
            else if(e == n2) c2++;
            else {
                if(c1 < c2)
                {
                    c1--;
                    if(c1 == 0){
                        n1 = e;
                        c1 = 1;
                    }
                } else {
                    c2--;
                    if(c2 == 0){
                        n2 = e;
                        c2 = 1;
                    }
                }
            }
        }
        
        int count = nums.size()/3;
        c1 = c2 = 0;
        for(auto e : nums)
        {
            if(e == n1) c1++;
            if(e == n2) c2++;
        }
        
        if(c1 > count) res.push_back(n1);
        if(c2 > count) res.push_back(n2);
        
        return res;
    }
};
