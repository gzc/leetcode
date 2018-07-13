class ExamRoom {
    
    set<int> taken;
    int n;
    
public:
    ExamRoom(int N) {
        n = N;
    }
    
    int seat() {
        if (taken.empty()) {
            taken.insert(0);
            return 0;
        }
  
        int ans = 0;
        int len = -1;

        if (taken.count(0) == 0) {
            len = max(len, *taken.begin());
            ans = 0;
        }

        int prevSeat = -1;
        for (int currentSeat : taken) {
            if (prevSeat < 0) {
                prevSeat = currentSeat;
            } else {
                // 6, 9 candidatelen = (6+9)/2 = 7 candidatelen = min(7-6, 9-7)
                int candidatePos = (currentSeat + prevSeat) / 2;
                int candidateLen = min(candidatePos - prevSeat, currentSeat - candidatePos);
                if (candidateLen > len) {
                    len = candidateLen;
                    ans = candidatePos;
                }
                prevSeat = currentSeat;
            }
        }
  
        if (taken.count(n-1) == 0) {
            int candidateLen = n - 1 - *taken.rbegin();
            if (candidateLen > len) {
                ans = n - 1;
            }
        }
  
        taken.insert(ans);
  
        return ans;
    }
    
    void leave(int p) {
        if (taken.count(p) > 0) {
            taken.erase(p);
        }
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */
