class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs), end(costs));
        int num = 0;
        for (int cost : costs) {
            if (coins >= cost) {
                num++;
                coins -= cost;
            } else {
                break;
            }
        }
        return num;
    }
};
