class Solution {
    
    int getMatch(int a) {
        if (a % 2 == 0) {
            return a + 1;
        } else {
            return a - 1;
        }
    }
    
    bool match(int a, int b) {
        return getMatch(a) == b;
    }
    
public:
    int minSwapsCouples(vector<int>& row) {
        int ans = 0;
        map<int, int> mymap;
        for (int i = 0; i < row.size(); i ++) {
            mymap[row[i]] = i;
        }
        vector<bool> visited(row.size()/2, false);
        
        for (int i = 0; i < row.size(); i += 2) {
            if (match(row[i], row[i+1])) continue;
            int loop = 0;
            int copy_i = i;
            while (true) {
                int virtual_index = copy_i / 2;
                if (visited[virtual_index]) break;
                visited[virtual_index] = true;
                int mismatch = row[copy_i];
                int match = getMatch(mismatch);
                int match_index = mymap[match];
                loop++;
                copy_i = getMatch(match_index);
            }
            
            ans += loop > 0 ? (loop - 1) : 0;
        }
        
        return ans;
    }
};
