class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        auto cmp1 = [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        };
        auto cmp2 = [](const vector<int> &a, const vector<int> &b) {
            return a[0] > b[0];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp1)> buy_backlog(cmp1);
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp2)> sell_backlog(cmp2);
        
        for (vector<int> order : orders) {
            if (order[2] == 0) {
                // buy order
                while (order[1] > 0 && !sell_backlog.empty()) {
                    if (sell_backlog.top()[0] > order[0]) {
                        break;
                    }
                    vector<int> sell_order = sell_backlog.top();
                    sell_backlog.pop();
                    
                    if (order[1] >= sell_order[1]) {
                        order[1] -= sell_order[1];
                    } else {
                        sell_order[1] -= order[1];
                        order[1] = 0;
                        sell_backlog.push(sell_order);
                    }
                }
                if (order[1] > 0) {
                    buy_backlog.push(order);
                }
            } else {
                while (order[1] > 0 && !buy_backlog.empty()) {
                    if (buy_backlog.top()[0] < order[0]) {
                        break;
                    }
                    vector<int> buy_order = buy_backlog.top();
                    buy_backlog.pop();
                    
                    if (order[1] >= buy_order[1]) {
                        order[1] -= buy_order[1];
                    } else {
                        buy_order[1] -= order[1];
                        order[1] = 0;
                        buy_backlog.push(buy_order);
                    }
                }
                if (order[1] > 0) {
                    sell_backlog.push(order);
                }
            }
        }
        
        int mod = 1e9+7;
        int ans = 0;
        while (!buy_backlog.empty()) {
            ans += buy_backlog.top()[1];
            ans %= mod;
            buy_backlog.pop();
        }
        while (!sell_backlog.empty()) {
            ans += sell_backlog.top()[1];
            ans %= mod;
            sell_backlog.pop();
        }
        return ans;
    }
};
