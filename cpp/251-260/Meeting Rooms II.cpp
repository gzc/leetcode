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
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> mymap;
        for (const Interval& interval : intervals) {
            mymap[interval.start]++;
            mymap[interval.end]--;
        }

        int cnt = 0, maxCnt = 0;
        for (auto it = mymap.begin(); it != mymap.end(); it++) {
            cnt += it->second;
            maxCnt = max(cnt, maxCnt);
        }

        return maxCnt;
    }
};
