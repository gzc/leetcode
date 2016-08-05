class Solution {
    
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> m = {{'0', '0'}, {'1', '1'}, {'6','9'}, {'8','8'}, {'9', '6'}};
        int len(num.length());
        
        for (int i = 0;i < (len+1)/2;i++)
        {
            if(m.count(num[i]) == 0) return false;
            if(m[num[i]] != num[len - i - 1]) return false;
        }
        return true;
    }
};
