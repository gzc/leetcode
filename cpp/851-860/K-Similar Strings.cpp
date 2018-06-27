class Solution {
public:
    int kSimilarity(string A, string B) {
        if(A == B) return 0;
        
        unordered_set<string> visit;
        queue<pair<string, int>> q;
        
        int n = A.size();
        int step = 0;
        
        int i = 0;
        for(; i < n; ++i) {
            if(A[i] != B[i]) break;
        }
        
        q.push({A, i});
        visit.insert(A);
        
        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; ++i) {
                string t = move(q.front().first);
                int index = q.front().second;
                q.pop();
                
                if(t == B) return step;
                
                while(t[index] == B[index]) ++index;
                for(int i = index +1; i < n; ++i) {
                    if(t[i] == B[index] && t[i] != B[i]) {
                        swap(t[index], t[i]);
                        
                        if(visit.count(t) == 0) {
                            q.push({t, index+1});
                            visit.insert(t);
                        }
                        
                        swap(t[index], t[i]);
                    }
                }
                
            }
            
            ++step;
        }
        
        return step;
    }
};
