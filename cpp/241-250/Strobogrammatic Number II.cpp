class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return helper(n , n);
    }
    vector<string> helper(int m, int n){
        if(m == 0) return vector<string>({""});
        if(m == 1) return vector<string>({"0", "1", "8"});
        vector<string> tmp = helper(m - 2, n), res;
        for(int i = 0; i < tmp.size(); i++){
            if(m != n) res.push_back("0" + tmp[i] + "0");
            res.push_back("1" + tmp[i] + "1");
            res.push_back("6" + tmp[i] + "9");
            res.push_back("8" + tmp[i] + "8");
            res.push_back("9" + tmp[i] + "6");
        }
        return res;
    }
};
