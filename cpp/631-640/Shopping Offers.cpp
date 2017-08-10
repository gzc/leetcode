class Solution {
    void dfs(int currentPrice, int offerIndex, vector<int>& price, vector<vector<int>>& special, vector<int> needs, int& result) {
        int n = price.size();
        int nextOffer = offerIndex + 1;
        if (nextOffer < special.size()) dfs(currentPrice, nextOffer, price, special, needs, result);
        for (int k = 0; ; k++) {
            bool finished = true;
            for (int i = 0; i < special[offerIndex].size() - 1; i++) {
                needs[i] -= special[offerIndex][i];
                if (needs[i] < 0) return;
                if (needs[i] > 0) finished = false;
            }
            currentPrice += special[offerIndex].back();
            if (finished) {
                result = min(currentPrice, result);
                return;
            }
            if (nextOffer < special.size()) dfs(currentPrice, nextOffer, price, special, needs, result);
        }
    }
    
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();
        int result = INT_MAX;
        for (int i = 0; i < n; i++) {
            vector<int> temp(n + 1, 0);
            temp[temp.size() - 1] = price[i];
            temp[i] = 1;
            special.push_back(temp);
        }
        
        dfs(0, 0, price, special, needs, result);
        return result == INT_MAX ? 0 : result;
    }
};
