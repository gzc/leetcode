class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> m;
        vector<int> result;
        for (int i = 0;i < numbers.size();i++) {
            int remain = target - numbers[i];
            if (m.count(remain) > 0) {
                result.push_back(m[remain]);
                result.push_back(i);
                return result;
            }
            m[numbers[i]] = i;
        }
        return result;
    }
};
