class Solution {
    
    bool Valid(string s)
    {
        if(s.length() == 1){
            return true;
        }
        else if(s.length() == 2){
            if(s >= "10" && s <= "99") 
                return true;
        }
        else if(s.length() == 3){
            if(s >= "100" && s <= "255") 
                return true;
        }
        return false;
    }
    
    void help(string s, int level, int index, vector<string>& r, vector<string> temp)
    {
        
        if(level == 4 && index == s.length()) {
            string line = temp[0];
            for(int i = 1;i < 4;i++)
            {
                line += '.';
                line += temp[i];
            }
            r.push_back(line);
        } else if(level == 4 && index < s.length()) {
            return;
        }
        
        for(int i = 0;i < 3;i++)
        {
            if(index + i + 1 > s.length())
                return;
            string tmp = s.substr(index,i+1);

            if( Valid(tmp) ){
                temp.push_back(tmp);
                help(s, level+1, index+i+1, r, temp);
                temp.pop_back();
            }
        }
    }
    
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> results;
        vector<string> temp;
        if(s.length() > 12 && s.length() < 4)
            return results;
        
        help(s, 0, 0, results, temp);
        
        return results;
    }
    
};
