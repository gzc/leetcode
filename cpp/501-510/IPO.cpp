class Compare1 {
public:
    bool operator() (const pair<int,int>& p1, const pair<int,int>& p2) {
        return p1.second - p2.second >= 0;
    }
};

class Compare2 {
public:
    bool operator() (const pair<int,int>& p1, const pair<int,int>& p2) {
        return p2.first - p1.first >= 0;
    }
};

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<pair<int, int>, vector<pair<int,int>>, Compare1> stocks;
        priority_queue<pair<int, int>, vector<pair<int,int>>, Compare2> avaliable;
        
        for (int i = 0; i < Profits.size(); i++) {
            stocks.push({Profits[i], Capital[i]});
        }
        
        for (int i = 0; i < k; i++) {
            
            while (!stocks.empty() && stocks.top().second <= W) {
                avaliable.push(stocks.top());
                stocks.pop();
            }
            
            if (!avaliable.empty()) {
                W += avaliable.top().first;
                avaliable.pop();
            }
        }
        
        return W;
    }
};
