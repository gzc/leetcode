class Solution {
public:
    int compress(vector<char>& chars) {
        int cnt = 1;
        char cur = chars[0];
        int writePos = 0;
        for (int i = 0; i < chars.size(); i++) {
            bool shouldWrite = i == chars.size() - 1 || cur != chars[i+1];

            if (shouldWrite) {
                chars[writePos++] = cur;
                if (cnt > 1) {
                    string tmp = to_string(cnt);
                    for (char t : tmp) {
                        chars[writePos++] = t;
                    }
                }
                cur = chars[i+1];
                cnt = 1;
            } else {
                cnt++;
            }
        }
        return writePos;
    }
};
