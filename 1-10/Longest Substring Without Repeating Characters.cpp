#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        bool p[256] = {false};
        int result(0),cur(0);
        
        for(int i = 0;i < s.length();i++) {
            char ch = s[i];
            if(!p[ch]) {
                cur++;
                p[ch] = true;
                result = max(result, cur);
            } else {
                int index = i - cur;
                for(int j = i - cur;;j++) {
                    if(s[j] == ch) {
                        cur = i - j;
                        break;
                    } else {
                        p[s[j]] = false;
                    }
                }
            }
        }
        
        return result;
    }
};

int main()
{
    Solution s;
    int result = s.lengthOfLongestSubstring("ddfjhsabcabcbb");
    
    cout << result;
    
    return 0;
}