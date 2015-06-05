class Solution {
    
    int CMP(string s1, string s2)
    {
        while(s1.length() > 1 && s1[0] == '0')
            s1 = s1.substr(1);
        while(s2.length() > 1 && s2[0] == '0')
            s2 = s2.substr(1);

        if(s1.length() > s2.length())
            return 1;
        if(s1.length() < s2.length())
            return -1;
        
        int len = s1.length();
        for(int i = 0;i < len;i++)
        {
            if(s1[i] > s2[i])
                return 1;
            if(s1[i] < s2[i])
                return -1;
        }
        
        return 0;
        
    }
    
    bool zero(string s)
    {
        for(int i = 0;i < s.length();i++)
        {
            if(s[i] == '0' || s[i] == '.')
                continue;
            else
                return false;
        }
        return true;
    }
    
public:
    int compareVersion(string version1, string version2) {
        
        int dot1 = version1.find('.');
        int dot2 = version2.find('.');
        
        if(dot1 > 0 && dot2 > 0){
            int flag = CMP(version1.substr(0, dot1), version2.substr(0, dot2));
            if(flag != 0) return flag;
            else return compareVersion(version1.substr(dot1+1), version2.substr(dot2+1));
        }
        
        else if(dot1 > 0 && dot2 < 0){
            int flag = CMP(version1.substr(0, dot1), version2);
            if(flag != 0) return flag;
            if(zero(version1.substr(dot1+1))) return 0;
            else return 1;
        }
        
        else if(dot1 < 0 && dot2 > 0){
            int flag = CMP(version1, version2.substr(0, dot2));
            if(flag != 0) return flag;
            if(zero(version2.substr(dot2+1))) return 0;
            else return -1;
        }
        
        else {
            int flag = CMP(version1, version2);
            return flag;
        }
 
    }
};
