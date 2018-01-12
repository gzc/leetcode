/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<Interval> result;
        multiset<pair<int, bool>> myset;
        for (const vector<Interval>& intervals : schedule) {
            for (const Interval& interval : intervals) {
                myset.insert({interval.start, true});
                myset.insert({interval.end, false});
            }
        }
        
        int count = 0;
        int lastTime = -1;
        for (const pair<int, bool>& ele : myset) {
            if (ele.second) {
                if (lastTime != -1 && count == 0 && ele.first > lastTime) {
                    result.push_back(Interval(lastTime, ele.first));
                }
                count++;
            } else {
                count--;
            }
            lastTime = ele.first;
        }
        
        return result;
    }
};
