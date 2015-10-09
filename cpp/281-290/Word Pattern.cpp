class Solution {
public:
    bool wordPattern(string pattern, string str) {
        stringstream ss(str);
        map<char, string>m;
        map<string, bool>m2;
        
        for(int i = 0;i < pattern.length();i++)
        {
            char ch = pattern[i];
            string temp;
            ss >> temp;
            
            if(temp == "") return false;
            
            if(m.count(ch) == 0)
            {
                if(m2[temp] == true) return false;
                m[ch] = temp;
                m2[temp] = true;
            } else {
                if(m[ch] != temp)
                    return false;
            }
        }
        
        string test;
        ss >> test;
        if(test.length() > 0) return false;
        
        return true;
    }
};