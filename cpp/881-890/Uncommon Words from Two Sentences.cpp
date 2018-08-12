class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> count;
        istringstream iss(A + " " + B);
        while (iss >> A) count[A]++;
        vector<string> res;
        for (auto& w: count)
            if (w.second == 1)
                res.emplace_back(move(w.first));
        return res;
    }
};
