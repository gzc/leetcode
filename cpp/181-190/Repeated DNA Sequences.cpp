class Solution {
    
private:
    inline int change(char ch) {
        if (ch == 'A') return 0;
        if (ch == 'C') return 1;
        if (ch == 'G') return 2;
        return 3;
    }

public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> m;
        int len = s.length();
        vector<string>results;
        
        int tmp(0);
        
        for(int i = 0;i < 10;i++) {
            tmp *= 4;
            tmp += change(s[i]);
        }
        m[tmp] = 1;

        for (int i = 1; i <= len-10; i++) {
            tmp = tmp - change(s[i-1])*262144;
            tmp *= 4;
            tmp += change(s[i+9]);
            if (m[tmp] == -1) continue;
            else if(m[tmp] == 1) { results.push_back(s.substr(i,10)); m[tmp] = -1; }
            else m[tmp] = 1;
        }

        return results;
    }
};
