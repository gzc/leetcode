class Solution {
    
    string transform(string str, int index, int sign) {
        int i = str[index] - '0';
        if (sign > 0) i = (i + 1)%10;
        else i = (i + 9)%10;
        char ch = i + '0';
        str[index] = ch;
        return str;
    }
    
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string, int>> myqueue;
        set<string> deadset(deadends.begin(), deadends.end());
        set<string> visited;
        if (deadset.count("0000") == 0) myqueue.push({"0000", 0});
        
        while (!myqueue.empty()) {
            auto ele = myqueue.front();
            myqueue.pop();
            
            if (ele.first == target) {
                return ele.second;
            }
            
            visited.insert(ele.first);
            
            for (int i = 0; i < 4; i++) {
                for (int sign = 0; sign < 2; sign++) {
                    string str = transform(ele.first, i, sign);
                    if (deadset.count(str) == 0 && visited.count(str) == 0) {
                        visited.insert(str);
                        myqueue.push({str, ele.second + 1});
                    }
                }
            }
        }
        
        return -1;
    }
};
