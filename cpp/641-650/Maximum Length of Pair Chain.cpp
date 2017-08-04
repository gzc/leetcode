class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>&b) {
            return a[1] < b[1] || a[1] == b[1] && a[0] < b[0];
        });
        
        int cnt = 0;
        vector<int>& pair = pairs[0];
        for (const vector<int>& ele : pairs) {
            if (cnt == 0 || ele[0] > pair[1]) {
                pair = ele;
                cnt++;
            }
        }
        return cnt;
    }
};
