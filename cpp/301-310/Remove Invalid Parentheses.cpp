class Solution {
    
    int check(const string &s) {
        stack<char> mystack;
        int num(0);
        for (auto e : s) {
            if (e == '(') mystack.push(e);
            else if (e == ')') {
                if(mystack.empty()) num++;
                else mystack.pop();
            }
        }
        return num + mystack.size();
    }
    
public:
    vector<string> removeInvalidParentheses(string s) {
        queue<string> myqueue;
        map<string, bool> mymap;
        myqueue.push(s);
        mymap[s] = true;
        vector<string> result;
        
        while(!myqueue.empty()) {
            string str = myqueue.front();
            int num1 = check(str);
            if (num1 == 0) break;
            myqueue.pop();
            int i = 0;
            while(i < str.length()) {
                if(str[i] != '(' && str[i] != ')') { i++; continue;}
                string tmp = str.substr(0,i) + str.substr(i+1);
                int num2 = check(tmp);
                if(mymap.count(tmp) == 0 && num2 < num1) {
                    myqueue.push(tmp);
                    mymap[tmp] = true;
                }
                while(i+1 < str.length() && str[i] == str[i+1]) i++;
                i++;
            }
        }
        
        int len = myqueue.front().length();
        while(!myqueue.empty() && myqueue.front().length() == len) {
            string tmp = myqueue.front();
            myqueue.pop();
            result.push_back(tmp);
        }
        
        return result;
    }
};
