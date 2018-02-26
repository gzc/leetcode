class Solution {
public:
    string customSortString(string S, string T) {
        map<char, int> mymap;
        for (char ch : T) mymap[ch]++;
        string result;
        for (char ch : S) {
            string temp(mymap[ch], ch);
            result += temp;
            mymap[ch] = 0;
        }
        for (const auto& it : mymap) {
            if (it.second > 0) {
                string temp(it.second, it.first);
                result += temp;
            }
        }
        return result;
    }
};
