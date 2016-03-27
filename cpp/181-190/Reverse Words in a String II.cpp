class Solution {
public:
    void reverseWords(string &s) {
        stringstream ss(s);
        string result = "";
        string temp;
        while(ss >> temp)
        {
            if(temp.size() == 0) break;
            result = temp + " " + result;
        }
        s = result.substr(0, result.length()-1);
    }
};
