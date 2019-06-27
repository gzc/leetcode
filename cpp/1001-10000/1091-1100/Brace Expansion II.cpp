class Solution {
    
    set<string> merge(const set<string>& set1, const set<string>& set2) {
        set<string> ans;
        for (const string& str1 : set1) {
            for (const string& str2 : set2) {
                ans.insert(str1+str2);
            }
        }
        return ans;
    }
    
    void process(stack<set<string>>& mystack, stack<char>& ops) {
        char op = ops.top();
        ops.pop();
        set<string> set1 = mystack.top();
        mystack.pop();
        set<string> set2 = mystack.top();
        mystack.pop();
        if (op == '*') {
            set<string> merged = merge(set2, set1);
            mystack.push(merged);
        } else if (op == ',') {
            set1.insert(set2.begin(), set2.end());
            mystack.push(set1);
        }
    }
    
public:
    vector<string> braceExpansionII(string expression) {
        stack<char> ops;
        stack<set<string>> mystack;
        expression = "{" + expression + "}";
        
        string word;
        for (int i = 0; i < expression.length(); i++) {
            
            if (!word.empty() && (expression[i] < 'a' || expression[i] > 'z' || i + 1 == expression.length())) {
                set<string> set_;
                set_.insert(word);
                mystack.push(set_);
                word.clear();
            }
            
            if (expression[i] == '{') {
                if (i != 0 && (expression[i-1] != ',' && expression[i-1] != '{')) {
                    ops.push('*');
                }
                ops.push('{');
            } else if (expression[i] == '}') {
                while (ops.top() != '{') {
                    process(mystack, ops);
                }
                ops.pop();
            } else if (expression[i] == ',') {
                while (ops.top() == '*') {
                    process(mystack, ops);
                }
                ops.push(',');
            } else {
                if (word.empty() && i != 0 && expression[i-1] == '}') {
                    ops.push('*');
                }
                word = word + expression[i];
            }
        }
        
        return vector<string>(mystack.top().begin(), mystack.top().end());
    }
};
