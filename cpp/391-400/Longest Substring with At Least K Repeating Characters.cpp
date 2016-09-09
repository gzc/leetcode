class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.size() == 0 || k > s.size())   return 0;
        if(k == 0)  return s.size();
        
        unordered_map<char,int> Map;
        for(int i = 0; i < s.size(); i++){
            Map[s[i]]++;
        }
        
        int idx =0;
        while(idx <s.size() && Map[s[idx]] >= k)    idx++;
        if(idx == s.size()) return s.size();
        
        int left = longestSubstring(s.substr(0 , idx) , k);
        int right = longestSubstring(s.substr(idx+1) , k);
        
        return max(left, right);
    }
};
