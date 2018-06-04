class Solution {
    
    string parse(const string& str) {
        stack<char> mystack;
        int i = 0;
        while (i < str.length()) {
            if (str[i] != '#') {
                mystack.push(str[i]);
            } else if (!mystack.empty()){
                mystack.pop();
            }
            i++;
        }
        string ans;
        while (!mystack.empty()) {
            ans += mystack.top();
            mystack.pop();
        }
        return ans;
    }
    
public:
    bool backspaceCompare(string S, string T) {
        return parse(S) == parse(T);
    }
};
