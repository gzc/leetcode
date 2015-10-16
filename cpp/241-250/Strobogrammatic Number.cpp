class Solution {
    
public:
    bool isStrobogrammatic(string num) {
        map<char, char> m;
        m['6'] = '9';
        m['9'] = '6';
        m['1'] = '1';
        m['8'] = '8';
        m['0'] = '0';
        
        string temp = "";
        int len = num.length();
        
        for(int i = 0;i < (len+1)/2;i++)
        {
            if(m.count(num[i]) == 0) return false;
            if(m[num[i]] != num[len - i - 1]) return false;
        }
        return true;
    }
};