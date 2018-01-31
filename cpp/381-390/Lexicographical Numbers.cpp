class Solution {
    
    void dfs(int curr, int n, vector<int>& result, int& index) {
        if (curr <= n) {
            result[index++] = curr;
        } else {
            return;   
        }
        
        for (int i = 0; i <= 9; i++) {
            dfs(curr*10 + i, n, result, index);
        }
    }
    
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result(n);
        int index = 0;
        
        for (int i = 1; i <= 9; i++)
            dfs(i, n, result, index);
        
        return result;
    }
};
