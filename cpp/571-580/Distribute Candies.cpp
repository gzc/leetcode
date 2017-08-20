class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int n = candies.size();
        set<int> myset;
        for (int e : candies) {
            myset.insert(e);
        }
        if (myset.size() >= n / 2) {
            return n/2;
        } else {
            return myset.size();
        }
    }
};
