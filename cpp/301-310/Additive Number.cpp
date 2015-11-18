class Solution {
    
    bool check(string add1, string add2, int index, string &num) {
        while(1) {
            if(add1.length() > 1 && add1[0] == '0') return false;
            if(add2.length() > 1 && add2[0] == '0') return false;
            long res = stol(add1) + stol(add2);
            
            string strres = to_string(res);
            if(index + strres.length() > num.length()) return false;
            string cmp = num.substr(index, strres.length());
            
            if(cmp != strres) return false;
            index += strres.length();
            if(index == num.length()) return true;
            
            add1 = add2;
            add2 = strres;
        }
        
        return false;
    }
    
public:
    bool isAdditiveNumber(string num) {
        
        if(num.length() < 3) return false;
        
        for(int len1 = 1;len1 <= num.length() - 2; len1++) {
            for(int len2 = 1; len1+len2 <= num.length() - 1;len2++) {
                bool f = check(num.substr(0, len1), num.substr(len1, len2), len1+len2, num);
                if(f) return true;
            }
        }
        return false;
    }
};