class Solution {
    
    int findroot(int c, vector<int> &u)
    {
        while(c != u[c]) c = u[c];
        return c;
    }
    
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        
        vector<int> u(n, 0);
        for(int i = 0;i < n;i++)
            u[i] = i;
        
        for(int i = 0;i < edges.size();i++)
        {
            int root1 = findroot(edges[i].first, u);
            int root2 = findroot(edges[i].second, u);
            if(root1 == root2) continue;
            
            u[root2] = root1;
            n--;
        }
        
        return n;
    }
};