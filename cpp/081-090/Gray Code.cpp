class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v{0};
        for (int i = 0; i < n; i++) {
            int len = v.size();
            for (int j = len-1; j >= 0; j--)
                v.push_back(v[j] | (1 << i) );
        }
        return v;
    }
};
