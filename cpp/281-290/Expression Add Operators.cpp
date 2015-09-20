class Solution {
    
    void help(vector<string>& result, string& num, int& target, int index, char op, int pv, int nv, string res)
    {
        if(index == num.size() && nv == target)
        {
            result.push_back(res);
            return;
        }
        
        for(int i = 1;i <= num.size()-index;i++)
        {
            string curnum = num.substr(index, i);
            int v = stol(curnum);
            if(curnum.length() != to_string(v).length()) continue;
            help(result, num, target, index+i, '+', v, nv+v, res+'+'+curnum);
            help(result, num, target, index+i, '-', v, nv-v, res+'-'+curnum);
            help(result, num, target, index+i, op, pv*v, op == '+'? nv - pv + pv*v : (op == '-'? nv + pv - pv*v : pv*v), res+'*'+curnum);
            
        }
    }
    
public:
    vector<string> addOperators(string num, int target) {
        
        vector<string> result;
        
        for(int i = 1;i <= num.size();i++)
        {
            string curnum = num.substr(0, i);
            int v = stol(curnum);
            if(curnum.length() != to_string(v).length()) continue;
            help(result, num, target, i, '!', v, v, curnum);
        }
        
        return result;
    }
};