/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
    
    int similarity(string& s1, string& s2) {
        int n = s1.length();
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            if (s1[i] == s2[i]) {
                ans++;
            }
        }
        
        return ans;
    }
    
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        vector<string> v(wordlist);
        for (int i = 0; i < 10; i++) {
            string candidate = v[v.size()/2];
            int n = master.guess(candidate);
            if (n == 6) return;
            vector<string> temp;
            for (int i = 0; i < v.size(); i++) {
                if (v[i] == candidate) continue;
                int similar = similarity(candidate, v[i]);
                if (similar == n) temp.push_back(v[i]);
            }
            v = temp;
        }
    }
};
