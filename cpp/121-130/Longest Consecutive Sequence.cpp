class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        
        unordered_map<int, int> p;
        int result(1);
        
        for(int i = 0;i < num.size(); i++)
        {
            p[num[i]] = 1;
        }
        
        for(int i = 0;i < num.size(); i++)
        {
            if(p[num[i]] == -1) continue;
            else {
                p[num[i]] = -1;
                int tmp = num[i];
                int r = 1;
                while(p.count(++tmp) > 0)
                {
                    r++;
                    p[tmp] = -1;
                }
                tmp = num[i];
                while(p.count(--tmp) > 0)
                {
                    r++;
                    p[tmp] = -1;
                }
                result = max(result,r);
            }
        }
        
        return result;
    }
};
