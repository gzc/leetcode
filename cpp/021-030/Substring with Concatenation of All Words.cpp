#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        
        int wl = L[0].length();
        int wc = L.size();
        int boundary = S.length() - wl;
        vector<int> res;
        unordered_map<string, int> dict;
        for(auto e : L) dict[e]++;
        
        for(int k = 0;k < wl;k++)
        {
            unordered_map<string, int> records;
            int count(0),left(k);
            
            for(int i = k;i <= boundary;i += wl)
            {
                string str = S.substr(i, wl);
                if(dict.count(str))
                {
                    records[str]++;
                    if(records[str] > dict[str])
                    {
                        while(records[str] > dict[str])
                        {
                            string s = S.substr(left, wl);
                            left += wl;
                            records[s]--;
                            if(records[s] < dict[s]) count--;
                        }
                    } else {
                        count++;
                    }
                    
                    if(count == wc)
                    {
                        res.push_back(left);
                        string s = S.substr(left, wl);
                        records[s]--;
                        left += wl;
                        count--;
                    }
                } else {
                    records.clear();
                    count = 0;
                    left = i + wl;
                }
            }
        }
        
        return res;
    }
    
    
};

int main()
{
    Solution s;

    string a[3] = {"a", "b", "a"};
    vector<string> ss(a,a+3);
    vector<int> v = s.findSubstring("abababab", ss);
    
    for(int i = 0;i < v.size();i++)
        cout << v[i] << endl;
    return 0;
}