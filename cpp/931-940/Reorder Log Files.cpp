class Solution {
public:
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        auto cmp = [](const string& l, const string& r) {
            int lp = l.find(" ");
            int rp = r.find(" ");
            return l.substr(lp) < r.substr(rp);
        };
        // In-place partition
        int left = logs.size() - 1;
        int right = logs.size() - 1;
        
        while (left > -1) {
            if (isdigit(logs[left].back())) {
                swap(logs[left], logs[right]);
                --right;
            }
            --left;
        }
        
        // lexicographic order sort
        sort(logs.begin(), logs.begin() + right + 1, cmp);
        
        return logs;
    }
};
