class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        int visited[26] = {false};
        int cnt[26] = {0};
        for(char ch : s) cnt[ch-'a']++;
        stack<char> mystack;
        
        for(int i = 0;i < s.length();cnt[s[i]-'a']--,i++) {
            
            if(!mystack.empty() && mystack.top() == s[i]) continue;
            if(visited[s[i]-'a']) continue;
            
            while(!mystack.empty() && mystack.top() > s[i] && cnt[mystack.top() - 'a'] > 0) {
                visited[mystack.top() - 'a'] = false;
                mystack.pop();
            }
            
            mystack.push(s[i]);
            visited[s[i]-'a'] = true;
        }
        
        string res;
        while(!mystack.empty()) {
            res = mystack.top() + res;
            mystack.pop();
        }
        return res;
    }
};