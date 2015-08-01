class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int a[255] = {0};
        
        for(auto e : s)
            a[e]++;
        for(auto e : t)
            a[e]--;
        for(int i = 0;i < 255;i++)
            if(a[i] != 0)
                return false;
        return true;
        
    }
};