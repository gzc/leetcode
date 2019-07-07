class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> ans(n, 0);
        int depth = 0;
        
        for (int i = 0; i < seq.size(); i++) {
            if (seq[i] == '(') {
                depth++;
                if (depth % 2 == 0) ans[i] = 1;
            } else {
                depth--;
                if (depth % 2 == 1) ans[i] = 1;
            }
        }
        
        return ans;
    }
};
