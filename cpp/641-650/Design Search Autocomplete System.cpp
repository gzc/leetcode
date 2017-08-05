class AutocompleteSystem {
    unordered_map<string, int> dict;
    string prefix;

public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        for (int i = 0; i < times.size(); i++)
            dict[sentences[i]] += times[i];
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            dict[prefix]++;
            prefix.clear();
            return {};
        }

        prefix.push_back(c);
        auto cmp = [](const pair<string, int> &a, const pair<string, int> &b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };

        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);

        for (const auto& ele : dict) {
            auto res = std::mismatch(prefix.begin(), prefix.end(), ele.first.begin());
            if (res.first == prefix.end()){
                pq.push(ele);
                if (pq.size() > 3) {
                    pq.pop();
                }
            }
        }

        vector<string> res(pq.size());
        for (int i = pq.size() - 1; i >= 0; i--) {
            res[i] = pq.top().first;
            pq.pop();
        }
        return res;
    }
};
