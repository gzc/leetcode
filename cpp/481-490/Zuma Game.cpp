class Solution {
    
    int dfs(string board, string hand, unordered_map<string, int>& cache) {
        if (board.empty()) return 0;
        if (hand.empty()) return 999;
        string key = board + ":" + hand;
        if (cache.count(key) > 0) return cache[key];
        int step = 10;
                
        for (int i = 0;i <= board.size();i++) {
            
            int res = 0;
            int idx = hand.find(board[i]);
            if (idx < 0) continue;
            
            if (i+1 < board.size() && board[i] == board[i+1]) {
                string nhand = hand.substr(0, idx) + hand.substr(idx+1);
                string after_board = board.substr(0,i) + board.substr(i+2);
                simplify(after_board);
                if (after_board.empty()) return 1;
                res = 1 + dfs(after_board, nhand, cache);
            } else if (idx + 1 < hand.size() && hand[idx] == hand[idx+1]) {
                string nhand = hand.substr(0, idx) + hand.substr(idx+2);
                string after_board = board.substr(0,i) + board.substr(i+1);
                simplify(after_board);
                if (after_board.empty()) return 2;
                res = 2 + dfs(after_board, nhand, cache);
            } else {
                continue;
            }
            
            step = min(step, res);
            while (i+1 < board.size() && board[i] == board[i+1]) i++;
        }

        
        return cache[key] = step;
    }
    
public:
    int findMinStep(string board, string hand) {
        
        sort(hand.begin(), hand.end());
        
        unordered_map<string, int> cache;
        
        int step = dfs(board, hand, cache);
        
        return step > 5 ? -1 : step;
    }
    
    void simplify(string& str) {
        while(str.size() > 0) {
            int start = 0;
            bool done = true;
            for (int i = 0; i <= str.size(); i++) {
                if (i == str.size() || str[i] != str[start]) {
                    if (i - start >= 3) {
                        str = str.substr(0, start) + str.substr(i);
                        done = false;
                        break;
                    }
                    start = i;
                }
            }
            if (done) break;
        }
    }
};
