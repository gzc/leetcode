class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int, int> count;
        for (int age : ages) count[age]++;
        int res = 0;
        for (const auto &a: count) {
            for (const auto &b: count) {
                if (request(a.first, b.first)) {
                    res += a.second * (b.second - (a.first == b.first ? 1 : 0));
                }
            }
        }
        return res;
    }

    bool request(int a, int b) {
        return !(b <= 0.5 * a + 7 || b > a || (b > 100 && a < 100));
    }
};
