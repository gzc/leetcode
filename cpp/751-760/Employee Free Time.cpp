/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        map<int, int> mymap;
        for (const vector<Interval>& s : schedule) {
            for (const Interval& i : s) {
                mymap[i.start]++;
                mymap[i.end]--;
            }
        }
        
        int last = -1;
        int cnt = 0;
        vector<Interval> ans;
        
        for (const auto& pair : mymap) {
            int pcnt = cnt;
            cnt += pair.second;
            
            if (pcnt == 0 && last != -1) {
                Interval in(last, pair.first);
                ans.push_back(in);
            } else if (cnt == 0) {
                last = pair.first;
            }
        }
        
        return ans;
    }
};
