class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int h = citations.size();
        for (int i = 0;i < citations.size();i++) {
            if (citations[i] >= h)
                break;
            h--;
        }
        return h;
    }
};
