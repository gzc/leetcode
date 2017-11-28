class Solution {
public:
    string nextClosestTime(string time) {
        int cur = 60 * stoi(time.substr(0, 2)) + stoi(time.substr(3));
        set<int> allowed;
        for (char c : time) if (c != ':') allowed.insert(c - '0');

        while (true) {
            bool found = true;
            cur = (cur + 1) % (24 * 60);
            int digits[4] = {cur / 60 / 10, cur / 60 % 10, cur % 60 / 10, cur % 60 % 10};
            for (int d: digits) if (allowed.count(d) == 0) {
                found = false;
                break;
            };
            if (!found) continue;
            string result;
            if (cur / 60 < 10) {
                result += "0";
            }
            result += to_string(cur / 60);
            result += ":";
            if (cur % 60 < 10) {
                result += "0";
            }
            result += to_string(cur % 60);
            return result;
        }
    }
};
