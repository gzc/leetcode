class Solution {
    
    vector<string> split(const string &s, char delim) {
        vector<string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            if (item.length() > 0) {
                elems.push_back(item);
            }
        }
        return elems;
    }
    
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> ans;
        
        for (int i = 0; i < transactions.size(); i++) {
            vector<string> to_check = split(transactions[i], ',');
            int amount = stoi(to_check[2]);
            if (amount > 1000) {
                ans.push_back(transactions[i]);
                continue;
            }
            int i_time = stoi(to_check[1]);
            for (int j = 0; j < transactions.size(); j++) {
                if (i == j) continue;
                vector<string> v = split(transactions[j], ',');
                if (to_check[0] != v[0]) continue;
                if (to_check[3] == v[3]) continue;
                int j_time = stoi(v[1]);
                if (abs(i_time - j_time ) > 60) continue;

                ans.push_back(transactions[i]);
                break;
            }
        }
        
        return ans;
    }
};
