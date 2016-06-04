class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> m;
        vector<int> r;
        for(int i = 0;i < numbers.size();i++) {
            int remain = target - numbers[i];
            if(m.count(remain) > 0) {
                r.push_back(m[remain]);
                r.push_back(i);
                return r;
            }
            m[numbers[i]] = i;
        }
        return r;
    }
};
