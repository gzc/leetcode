#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
    
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        
        int l = L[0].length();
        int n = L.size();
        vector<int>result;
        
        unordered_map<string, int> p;
        
        for(int i = 0;i < n;i++)
            p[L[i]]++;
        
        int limi = S.length() - n*l;
        
        for(int k = 0;k < l;k++)
        {
            unordered_map<string, int>backup;
            queue<string>q;
            int index = k;
        
            for(int i = k;i <= limi;)
            {
                
                while(1)
                {
                    string s = S.substr(index,l);
                    backup[s]++;
                    
                    if(p.count(s) > 0 && backup[s] <= p[s])
                    {
                        q.push(s);
                        index += l;
                        if(q.size() == n)
                        {
                            result.push_back(i);
                            i += l;
                            string tmp = q.front();
                            q.pop();
                            backup[tmp]--;
                            break;
                        }
                    } else {
                        if(p.count(s) == 0)
                        {
                            i = index + l;
                            index = i;
                            while(!q.empty()) q.pop();
                            backup.clear();
                            break;
                        } else if(backup[s] > p[s]) {
                            index += l;
                            q.push(s);
                            cout << i <<" "<< index << endl;
                            while(1) {
                                i += l;
                                if(q.empty())
                                {
                                    break;
                                }
                                string tmp = q.front();
                                q.pop();
                                backup[tmp]--;
                                if(tmp == s)
                                {
                                    break;
                                }
                            }
                            break;
                        }
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

    string a[3] = {"a", "b", "a"};
    vector<string> ss(a,a+3);
    vector<int> v = s.findSubstring("abababab", ss);
    
    for(int i = 0;i < v.size();i++)
        cout << v[i] << endl;
    return 0;
}