// Solution 1: BFS
class Solution {
    
    int GetErrors(const string &s) {
        stack<char> mystack;
        int errors = 0;
        for (char ch : s) {
            if (ch == '(') {
                mystack.push(ch);
            } else if (ch == ')') {
                if (mystack.empty()) {
                    errors++;
                } else {
                    mystack.pop();
                }
            }
        }
        return errors + mystack.size();
    }
    
public:
    vector<string> removeInvalidParentheses(string s) {
        queue<string> myqueue;
        unordered_set<string> visited;
        myqueue.push(s);
        visited.insert(s);
        
        int errors = GetErrors(s);
        while (!myqueue.empty() && errors > 0) {
            int queue_size = myqueue.size();
            for (int k = 0; k < queue_size; k++) {
                string str = myqueue.front();
                myqueue.pop();
                int i = 0;
                while (i < str.length()) {
                    if (str[i] != '(' && str[i] != ')') {
                        i++;
                        continue;
                    }
                    string tmp = str.substr(0,i) + str.substr(i+1);
                    if (visited.count(tmp) == 0) {
                        int current_errors = GetErrors(tmp);
                        if (current_errors < errors) {
                            myqueue.push(tmp);
                            visited.insert(tmp);
                        }
                    }
    
                    while (i+1 < str.length() && str[i] == str[i+1]) i++;
                    i++;
                }
            }
            
            errors--;
        }
        
        vector<string> result;
        while (!myqueue.empty()) {
            string tmp = myqueue.front();
            myqueue.pop();
            result.push_back(tmp);
        }
        
        return result;
    }
};


// Solution 2: DFS
class Solution {
    
    int GetErrors(const string &s) {
        stack<char> mystack;
        int errors = 0;
        for (char ch : s) {
            if (ch == '(') {
                mystack.push(ch);
            } else if (ch == ')') {
                if (mystack.empty()) {
                    errors++;
                } else {
                    mystack.pop();
                }
            }
        }
        return errors + mystack.size();
    }
    
public:
    
    void dfs(const string& s, int ind, int validLen, int leftCnt, int rightCnt, string cur, unordered_set<string>& visited, unordered_set<string>& res_set) {
        if (cur.size() == validLen) {
            if (leftCnt == rightCnt) {
                res_set.insert(cur);
            }
            return;
        }
        if (ind >= s.size()) {
            return;
        }
        
        string key = to_string(ind) + cur;
        if (visited.count(key) > 0) return;
        visited.insert(key);
        
        if (s[ind] == '(' || s[ind] == ')') {
            if (cur.length() + (s.size() - ind) > validLen) {
                dfs(s, ind+1, validLen, leftCnt, rightCnt, cur, visited, res_set);
            }
            if (s[ind] == '(') {
                if (leftCnt < validLen / 2) {
                    dfs(s, ind+1, validLen, leftCnt+1, rightCnt, cur + '(', visited, res_set);
                }
            } else if (leftCnt > rightCnt) {
                dfs(s, ind+1, validLen, leftCnt, rightCnt+1, cur + ')', visited, res_set);
            }
        } else {
            dfs(s, ind+1, validLen, leftCnt, rightCnt, cur + s[ind], visited, res_set);
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int validLen = s.size() - GetErrors(s);
        unordered_set<string> visited;
        unordered_set<string> res_set;
        dfs(s, 0, validLen, 0, 0, "", visited, res_set);
        return vector<string>(res_set.begin(), res_set.end());
    }
};
