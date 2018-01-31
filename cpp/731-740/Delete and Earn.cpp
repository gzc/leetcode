class Solution {
    
    int rob(vector<int> &num) {
        if (num.empty()) return 0;
        
        int p[num.size()];
        p[0] = num[0];
        p[1] = max(num[0], num[1]);
        
        for (int i = 2;i < num.size();i++)
            p[i] = max(p[i-2] + num[i], p[i-1]);
        return p[num.size()-1];
    }
    
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> mymap;
        for (int e : nums) {
            mymap[e] += e;
        }
        
        vector<int> vec;
        int last = -1;
        for (auto& e : mymap) {
            if (last + 1 < e.first) {
                vec.push_back(0);
            }
            vec.push_back(e.second);
            last = e.first;
        }
        if (vec.size() == 1) return vec[0];
        return rob(vec);
    }
};
