class Solution {
public:
    string reverseVowels(string s) {
        int dict[256] = {0};
        dict['a'] = 1, dict['A'] = 1;
        dict['e'] = 1, dict['E'] = 1;
        dict['i'] = 1, dict['I'] = 1;
        dict['o'] = 1, dict['O'] = 1;
        dict['u'] = 1, dict['U'] = 1;
        int start = 0, end = (int)s.size() - 1;
        while(start < end){
            while(start < end && dict[s[start]] == 0) start++;
            while(start < end && dict[s[end]] == 0) end--;
            swap(s[start++],s[end--]);
        }
        return s;
    }
};