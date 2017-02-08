class Solution {
    
    int dfs(const string& s, int k, int start, int end) {
        int size = end-start+1;
        if(size == 0 || k > size)   return 0;
        if(k == 0)  return size;
        
        int Map[26] = {0};
        for(int i = start; i <= end; i++){
            Map[s[i]-'a']++;
        }
        
        int idx = start;
        while(idx <= end && Map[s[idx]-'a'] >= k)    idx++;
        if(idx == end+1) return size;
        
        int left = dfs(s, k, start, idx-1);
        int right = dfs(s, k, idx+1, end);
        
        return max(left, right);
    }
    
public:
    int longestSubstring(string s, int k) {
        return dfs(s, k, 0, s.length()-1);
    }
};
