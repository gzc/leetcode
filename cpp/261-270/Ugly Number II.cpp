class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v = {1};     
        int index2 = 0;
        int index3 = 0;
        int index5 = 0;
        int val = 1;
        
        while(--n)     
        {
            val = min(v[index2]*2, min(v[index3]*3, v[index5]*5));  
            v.push_back(val);
            if (val == v[index2]*2)    
                ++index2;
            if (val == v[index3]*3) 
                ++index3;
            if (val == v[index5]*5)
                ++index5;
        }
        return val;
    }
};
