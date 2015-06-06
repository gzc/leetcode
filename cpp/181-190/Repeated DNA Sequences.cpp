class Solution {
    
private:
    int change(char ch)
    {
        if(ch == 'A') return 1;
        if(ch == 'C') return 2;
        if(ch == 'G') return 3;
        return 4;
    }

public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> m;
        int len = s.length();
        vector<string>results;
        
        int tmp(0);
        
        for(int i = 0;i < 10;i++)
        {
            tmp *= 5;
            tmp += change(s[i]);
        }

        
        for(int i = 0;i <= len-10;i++)
        {
            if(i != 0){
                tmp = tmp - change(s[i-1])*1953125;
                tmp *= 5;
                tmp += change(s[i+9]);
            }
            if(m[tmp] == -1) continue;
            else if(m[tmp] == 1) { results.push_back(s.substr(i,10)); m[tmp] = -1; }
            else m[tmp] = 1;
        }

        
        return results;
    }
    
};
