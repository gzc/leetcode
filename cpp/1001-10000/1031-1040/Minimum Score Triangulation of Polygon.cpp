class Solution {
    
    int dfs(vector<int>& A, map<pair<int, int>, int>& cache, int start_index, int end_index) {
        pair<int, int> key = {start_index, end_index};
        auto it = cache.find(key);
        if (it != cache.end()) return it->second;
        
        if (end_index - start_index < 2) {
            return 0;
        }
        if (end_index - start_index == 2) {
            return A[start_index] * A[start_index+1] * A[start_index+2];
        }
        
        int ans = INT_MAX;
        for (int i = start_index+1; i < end_index; i++) {
            int current = A[start_index] * A[i] * A[end_index];
            current += dfs(A, cache, start_index, i);
            current += dfs(A, cache, i, end_index);
            ans = min(ans,  current);
        }
        
        return cache[key] = ans;
    }
    
public:
    int minScoreTriangulation(vector<int>& A) {
        map<pair<int, int>, int> cache;
        return dfs(A, cache, 0, A.size() - 1);
    }
};
