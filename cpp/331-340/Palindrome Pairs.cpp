class Solution {
    
    unordered_map<string, int> mymap;
    
    bool isPalindrome(string word) {
            int size = word.length();
            for(int i = 0;i < size/2;i++)
                if(word[i] != word[size - i - 1])
                    return false;
            return true;
    }
    
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        vector<vector<int>> ans;
        
        for(int i = 0;i < words.size();i++)
            mymap[words[i]] = i;
        
        for(int i = 0;i < words.size();i++) {
            string word = words[i];
        
            if (mymap.count("") > 0 && word != "" && isPalindrome(word)) {
                int bidx = mymap[""];
                vector<int> v1 = {i, bidx};
                vector<int> v2 = {bidx, i};
                ans.push_back(v1);
                ans.push_back(v2);
            }

            string rword = string(word.rbegin(), word.rend());
            
            if (mymap.count(rword) > 0) {
                int ridx = mymap[rword];
                if (i != ridx) {
                    vector<int> v1 = {i, ridx};
                    ans.push_back(v1);
                }
            }

            for(int j = 1;j < word.length();j++) {
                string left = word.substr(0, j);
                string rleft = string(left.rbegin(), left.rend());
                string right = word.substr(j);
                string rright = string(right.rbegin(), right.rend());
                if(isPalindrome(left) && mymap.count(rright) > 0) {
                    vector<int> v1 = {mymap[rright], i};
                    ans.push_back(v1);
                }
                if(isPalindrome(right) && mymap.count(rleft) > 0) {
                    vector<int> v1 = {i, mymap[rleft]};
                    ans.push_back(v1);
                }
                
            }
        }
        return ans;
    }
};
