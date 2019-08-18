class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char, int> mymap;
        for (char ch : chars) {
            mymap[ch]++;
        }
        
        int res = 0;
        
        map<char, int> copy = mymap;
        for (const string& word : words) {
            bool ok = true;
            
            for (char ch : word) {
                mymap[ch]--;
                if (mymap[ch] < 0) {
                    ok = false;
                    break;
                }
            }
            
            if (ok) res += word.length();
            mymap = copy;
        }
        
        return res;
    }
};
