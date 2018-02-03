class Solution {
    
    pair<int, int> parse(string str) {
        int xCount = 0, dCount = 0;
        int i = 0;
        int sign = 1;
        while (i < str.length()) {
            if (str[i] == '+') { sign = 1; i++; continue;} 
            if (str[i] == '-') { sign = -1; i++; continue;}
            int num = -1;
            if (isdigit(str[i])) {
                while (i < str.length() && isdigit(str[i])) {
                    if (num < 0) num = str[i] - '0';
                    else num = num * 10 + (str[i] - '0');
                    i++;
                }
                
                if (i >= str.length()) {
                    dCount += (sign * num);
                    break;
                }
            }
            
            if (str[i] == 'x') {
                if (num == -1) num = 1;
                xCount += (sign * num);
                i++;
            } else {
                dCount += (sign * num);
            }
        }
        return {xCount, dCount};
    }
    
public:
    string solveEquation(string equation) {
        int index = equation.find("=");
        string left = equation.substr(0, index);
        string right = equation.substr(index + 1);
        
        pair<int, int> temp1 = parse(left);
        pair<int, int> temp2 = parse(right);
        
        int d = temp2.second - temp1.second;
        int x = temp1.first - temp2.first;
        
        if (x == 0) {
            if (d == 0) {
                return "Infinite solutions";
            } 
            return "No solution";
        }
        return "x=" + to_string(d/x);
    }
};
