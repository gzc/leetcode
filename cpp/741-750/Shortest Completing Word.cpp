class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        transform(licensePlate.begin(), licensePlate.end(), licensePlate.begin(), ::tolower);
        int counts[26] = {0};
        string ans = "";
        for (char ch : licensePlate) {
            if (isalpha(ch)) {
                counts[ch - 'a']++;
            }
        }
        
        for (const string& word : words) {
            int temp[26] = {0};
            for (char ch : word) {
                temp[ch - 'a']++;
            }
            
            bool match = true;
            for (int i = 0; i < 26; i++) {
                if (counts[i] > temp[i]) {
                    match = false;
                    break;
                }
            }
            
            if (match && ( ans.empty() || ans.length() > word.length() )) {
                ans = word;
            }
        }
        
        return ans;
    }
};
