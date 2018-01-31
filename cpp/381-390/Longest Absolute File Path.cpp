class Solution {
public:
    int lengthLongestPath(string input) {
        stack<string> myfiles;
        
        int index = 0;
        int ans = 0;
        int temp = 0;
        
        while (true) {
            int nIndex = input.find("\n", index);
            string str = nIndex >= 0 ? input.substr(index, nIndex - index) : input.substr(index);
            
            int level = 0;
            while (str[level] == '\t') {
                level++;
            }
            
            string filename = str.substr(level);
            while (level < myfiles.size()) {
                string topFile = myfiles.top();
                myfiles.pop();
                temp -= topFile.length() ;
            }
            
            myfiles.push(filename);
            temp += filename.length();
                
            if (filename.find('.') != -1) {
                ans = max(ans, temp + (int)myfiles.size() - 1);
            }
            
            if (nIndex < 0) break;
            index = nIndex + 1;
        }
        
        return ans;
    }
};
