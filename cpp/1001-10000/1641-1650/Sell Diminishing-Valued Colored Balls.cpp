class Solution {
    
    long get(long a, long b) {
        return (a+b) * (b-a+1) / 2; 
    }
    
public:
    int maxProfit(vector<int>& inventory, int orders) {
        int n = inventory.size();
        long mod = 1e9+7;
        long ans = 0;
        
        map<int, int> mymap;
        
        for (int v : inventory) {
            mymap[v]++;
        }
        
        priority_queue<pair<int,int>> myqueue;
        
        for (const auto& it : mymap) {
            myqueue.push({it.first, it.second});
        }
        
        while (orders > 0) {
            pair<int, int> top = myqueue.top();
            myqueue.pop();
            
            pair<int, int> second;
            bool has_second = false;
            long to_num = 0;
            if (myqueue.size() > 0) {
                has_second = true;
                second = myqueue.top();
                myqueue.pop();
                to_num = second.first;
            }
            
            long from_num = top.first;
            long from_freq = top.second;
            int total_orders = (from_num - to_num) * from_freq;
            if (total_orders > orders) {
                int consume = orders/from_freq;
                to_num = from_num - consume;
                ans += (get(to_num+1, from_num) % mod) * from_freq % mod;
                orders -= from_freq*consume;
                while (orders > 0) {
                    ans += to_num;
                    ans %= mod;
                    orders--;
                }
            } else {
                ans += (get(to_num+1, from_num) % mod) * from_freq % mod;
                orders -= total_orders;
                myqueue.push({to_num, from_freq+second.second});
            }
        }
        
        ans %= mod;
        return ans;
    }
};
