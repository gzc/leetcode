class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        bool flag = false;
        vector<string> numStr;
        for (int num : nums) {
            if (num != 0) flag = true;
            numStr.emplace_back(to_string(num));
        }
        auto cmp = [](const string& i, const string& j) {
            return i + j > j + i;
        };
        sort(numStr.begin(), numStr.end(), cmp);
        for (const string& str : numStr) {
            res += str;
        }
        return flag ? res : "0";
    }
};
