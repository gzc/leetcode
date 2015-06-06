class Solution {
public:
    string simplifyPath(string path) {
        
        int pre = 0;
        int cur = 0;
        stack<string>p;
        path += "/";
        
        while( (cur = path.find("/", pre+1)) != string::npos)
        {
            string s = path.substr(pre+1, cur-pre-1);
            if(s == ".." && !p.empty()) p.pop();
            else if(s == ".." && p.empty()) {;}
            else if(s == ".") {;}
            else if(s.length() == 0) {;}
            else p.push(s);
            pre = cur;
        }
        
        string result = "";
        while(!p.empty())
        {
            result = "/" + p.top() + result;
            p.pop();
        }
        if(result.length() == 0) return "/";
        return result;
        
    }
};