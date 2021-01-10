class Solution {
    
    int ans;
    
    void dfs(vector<int>& jobs, int k, vector<int>& workers, int curr) {
        if (curr == jobs.size()) {
            ans = min(ans, *max_element(workers.begin(), workers.end()));
            return;
        }
            
        set<int> seen;
        for (int i = 0; i < k; i++) {
            if (seen.count(workers[i]) > 0) continue;
            if (workers[i] + jobs[curr] >= ans) continue;
            seen.insert(workers[i]);
            
            workers[i] += jobs[curr];
            dfs(jobs, k, workers, curr+1);
            workers[i] -= jobs[curr];
        }
    }
    
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        vector<int> workers(k, 0);
        ans = INT_MAX;
        
        dfs(jobs, k, workers, 0);
        return ans;
    }
};
