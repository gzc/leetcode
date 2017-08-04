class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rQ, dQ;
        for (int i = 0; i < senate.length(); i++) {
            if (senate[i] == 'R') {
                rQ.push(i);
            } else {
                dQ.push(i);
            }
        }
        
        while (!rQ.empty() && !dQ.empty()) {
            int rIndex = rQ.front();
            int dIndex = dQ.front();
            rQ.pop();
            dQ.pop();
            if (rIndex < dIndex) {
                rQ.push(rIndex + senate.length());
            } else {
                dQ.push(dIndex + senate.length());
            }
        }
        
        return rQ.empty() ? "Dire" : "Radiant";
    }
};
