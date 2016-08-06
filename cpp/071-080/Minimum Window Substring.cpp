class Solution {
public:
    string minWindow(string S, string T) {
        if (S.empty() || T.empty()) return "";
        int needed(T.size());
        int require[128] = {0};
        bool chSet[128] = {false};
        for (int i = 0; i < needed; ++i)
        {
            require[T[i]]++;
            chSet[T[i]] = true;
        }
        int left(0), right(-1);
        int minLen(INT_MAX), minIdx(0);
        while (right < (int)S.size()) {
            if (needed) {
                char ch = S[++right];
                require[ch]--;
                if (chSet[ch] && require[ch] >= 0) {
                    needed--;
                }
            }
            else {
                char ch = S[left];
                int temp_length = right-left+1;
                if (minLen > temp_length) {
                    minLen = temp_length;
                    minIdx = left;
                }
                require[ch]++;
                if (chSet[ch] && require[ch] > 0) {
                    needed++;
                }
                left++;
            }
        }
        if (minLen == INT_MAX) return "";
        return S.substr(minIdx, minLen);
    }
};
