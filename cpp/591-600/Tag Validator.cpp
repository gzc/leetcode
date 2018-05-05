class Solution {
public:
    bool isValid(string code)  {
        stack<string> stk;
	    for (int i = 0; i < code.length(); i++) {        
	        if (i > 0 && stk.empty()) return false;
	        if (code.substr(i, 9) == "<![CDATA[") {
		        int j = i + 9;
		        i = code.find("]]>", j);
		        if (i < 0) return false;
		        i += 2;
            } else if (code.substr(i, 2) == "</") {
                int j = i + 2;
                i = code.find('>', j);
                string s = code.substr(j, i - j);
                if (stk.empty() || s != stk.top()) return false;
                stk.pop();
	        } else if (code.substr(i, 1) == "<") {
                int j = i + 1;
                i = code.find('>', j);
                if (i < 0 || i == j || i - j > 9) return false;
                for (int k = j; k < i; k++) {
                    if (!isupper(code[k])) return false;
                }
                string s = code.substr(j, i - j);
                stk.push(s);
            }
        }
        return stk.empty();        
    }
};
