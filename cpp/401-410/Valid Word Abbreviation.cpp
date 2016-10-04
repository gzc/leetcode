class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int p1 = 0, p2 = 0;
        while (p1 < word.size() && p2 < abbr.size()) {
            //If a digit starts with 0, abbr is invalid
            if (abbr[p2] == '0')
                return false;

            //get the next digit
            int num = 0;
            while (p2 < abbr.size() && isdigit(abbr[p2])) {
                num = num * 10 + abbr[p2] - '0';
                p2++;
            }
            
            //increment the pointer in words
            p1 += num;
          
            //check current state is match or unmatch.
            if (p1 == word.size() && p2 == abbr.size()) {
                return true;
            } else if (p1 >= word.size() || p2 >= abbr.size() || word[p1] != abbr[p2]) {
                return false;
            }
            
            p1++;
            p2++;
        }
        
        return p1 == word.size() && p2 == abbr.size();
    }
};
