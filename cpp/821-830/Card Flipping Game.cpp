class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> same;
        for (int i = 0; i < fronts.size(); ++i)
            if (fronts[i] == backs[i])
                same.insert(fronts[i]);

        int ans = 2001;

        for (int x: fronts)
            if (same.count(x) == 0)
                ans = min(ans, x);

        for (int x: backs)
            if (same.count(x) == 0)
                ans = min(ans, x);

        return ans % 2001;
    }
};
