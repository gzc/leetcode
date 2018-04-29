class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> jobs;
        int N = profit.size(), res = 0, i = 0, maxp = 0;
        for (int j = 0; j < N; ++j) jobs.push_back(make_pair(difficulty[j], profit[j]));
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        for (int ability : worker) {
            while (i < N && ability >= jobs[i].first) maxp = max(jobs[i++].second, maxp);
            res += maxp;
        }
        return res;
    }
};
