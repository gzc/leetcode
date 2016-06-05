class Solution {
public:
    int myAtoi(string str) {
        int r(0);
        int sign(0);
        
        while(str[0] == ' ')
            str.erase(0, 1);
        
        while(str[0] == '+' | str[0] == '-')
        {
            if(sign != 0) return 0;
            else if(str[0] == '+') sign = 1;
            else sign = -1;
            str.erase(0, 1);
        }
        if(sign == 0) sign = 1;
        
        while(str[0] == '0')
            str.erase(0, 1);
        
        size_t len = str.size();
        
        for(int i = 0;i < len;i++)
        {
            if(!isdigit(str[i])) break;
            int v = str[i] - '0';

            if(r > INT_MAX/10)
            {
                if(sign == 1) return INT_MAX;
                if(sign == -1) return INT_MIN;
            } else if(r == INT_MAX/10)
            {
                if(sign == 1 && v > 7) return INT_MAX;
                if(sign == -1 && v > 8) return INT_MIN;
            }
            r = 10*r + v;

        }
        
        return r*sign;
    }
};
