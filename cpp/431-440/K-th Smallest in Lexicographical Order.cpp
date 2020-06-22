class Solution {
    
    int dfs(string prefix, int n) {
        string n_string = to_string(n);
        string ptrfix_of_n = n_string.substr(0, prefix.length());
        if (prefix.length() == n_string.length()) {
            return prefix <= n_string ? 1 : 0;
        }
        if (prefix > ptrfix_of_n) {
            int temp = 1;
            for (int k = 0; k < (n_string.length() - prefix.length() - 1); k++) {
                temp = temp * 10 + 1;
            }
            return temp;
        }
        if (prefix < ptrfix_of_n) {
            int temp = 1;
            for (int k = 0; k < (n_string.length() - prefix.length()); k++) {
                temp = temp * 10 + 1;
            }
            return temp;
        }
        
        int ans = 1;
        for (int i = 0; i <= 9; i++) {
            ans += dfs(prefix+to_string(i), n);
        }
        return ans;
    }
    
public:
    int findKthNumber(int n, int k) {
        string prefix = "";
        
        while (k > 0) {
            for (int i = 0; i <= 9; i++) {
                if (prefix.empty() && i == 0) continue;
                
                string new_prefix = prefix + to_string(i);
                int tmp = dfs(new_prefix, n);
                
                if (tmp >= k) {
                    prefix = new_prefix;
                    k -= 1;
                    break;
                } else {
                    k -= tmp;
                }
            }
            
        }
        
        return stoi(prefix);
    }
};
