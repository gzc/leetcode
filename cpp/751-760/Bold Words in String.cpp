class Solution {
private:
    vector<pair<int, int>> findpairs(const string& s, const vector<string>& dict) {
        vector<pair<int, int>> res;
        for (const string& w : dict) {
            int n = w.size();
            for (int i = 0; (i = s.find(w, i)) != string::npos; i++) {
                res.emplace_back(make_pair(i, i + n));
            }
        }
        return res;
    }

    vector<pair<int, int>> merge(vector<pair<int, int>>& a) {
        vector<pair<int, int>> r;
        auto cmp = [&](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first || a.first == b.first && a.second < b.second;
        };
        sort(a.begin(), a.end(), cmp);
        for (int i = 0, j = -1; i < a.size(); i++) {
            if (j < 0 || a[i].first > r[j].second) {
                r.push_back(a[i]);
                j++;
            } else {
                r[j].second = max(r[j].second, a[i].second);
            }
        }
        
        return r;
    }
public:
    string boldWords(vector<string>& words, string S) {
        vector<pair<int, int>> ranges = findpairs(S, words);
        ranges = merge(ranges);
        for (auto it = ranges.rbegin(); it != ranges.rend(); it++) {
            S.insert(it->second, "</b>");
            S.insert(it->first, "<b>");
        }
        return S;
    }
};

