class Solution {
    
    void merge(map<string,int> &local, const map<string, int>& inners) {
        for (auto it : inners) {
            local[it.first] += it.second;
        }
    }
    
    void multiply(map<string,int> &local, int k) {
        for (auto it : local) {
            local[it.first] = it.second * k;
        }
    }
    
    int parseValue(const string& formula, int& i) {
        int start = i;
        while (i < formula.size() && isdigit(formula[i])) {
            i++;
        }
        int value = 1;
        if (i > start) {
            value = stoi(formula.substr(start, i - start));
        }
        return value;
    }
    
    void parseOneItem(map<string,int> &local, const string& formula, int& i) {
        int start = i;
        while (i+1 < formula.size() && islower(formula[i+1])) {
            i++;
        }
        i++;
        string key = formula.substr(start, i - start);
        local[key] += parseValue(formula, i);
    }
    
    map<string, int> dfs(const string& formula, int& i) {
        map<string, int> locals;
        
        while (i < formula.size() && formula[i] != ')') {
            if (formula[i] == '(') {
                i++;
                map<string, int> inners = dfs(formula, i);
                merge(locals, inners);
            } else {
                parseOneItem(locals, formula, i);
            }
        }
        
        int k = 1;
        if (formula[i] == ')') {
            i++;
            k = parseValue(formula, i);
        }
        multiply(locals, k);
        
        return locals;
    }
    
public:
    string countOfAtoms(string formula) {
        int i = 0;
        map<string, int> counts = dfs(formula, i);
        
        string result = "";
        for (auto it : counts) {
            result += (it.first + (it.second > 1 ? to_string(it.second) : ""));
        }
        return result;
    }
};
