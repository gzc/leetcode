class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        map<int, int> counters;
        int n = nums.size();
        int start = INT_MAX;
        int end = INT_MIN;
        
        auto cmp = [](const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b) {
            return a.first >= b.first;
        };

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(cmp)> pq(cmp);
        
        for (int i = 0; i < n; i++) {
            pq.push({nums[i][0], {i, 0}});   // {value, {index of vector, index of element in this vector}}
            start = min(start, nums[i][0]);
            end = max(end, nums[i][0]);
        }
        
        vector<int> result{start, end};
        
        while (true) {
            if (end - start < result[1] - result[0]) {
                result[0] = start;
                result[1] = end;
            }
            pair<int, pair<int, int>> ele = pq.top();
            pq.pop();
            int v = ele.first;
            int numsIndex = ele.second.first;
            int eleIndex = ele.second.second;

            if (eleIndex + 1 < nums[numsIndex].size()) {
                pq.push({nums[numsIndex][eleIndex + 1], {numsIndex, eleIndex + 1}}); 
                end = max(end, nums[numsIndex][eleIndex + 1]);
            } else {
                break;
            }

            start = pq.top().first;
        }
        
        return result;
    }
};
