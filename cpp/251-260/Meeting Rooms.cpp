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
    bool canAttendMeetings(vector<Interval>& intervals) {
        auto comp = [&](const Interval &a, const Interval &b) { return a.start < b.start; };
        sort(intervals.begin(), intervals.end(), comp);
        int n = intervals.size();
        for (int i = 0; i < n - 1; i++)
            if (overlap(intervals[i], intervals[i + 1]))
                return false;
        return true;
    }
private:
    bool overlap(Interval& interval1, Interval& interval2) {
        return interval1.end > interval2.start;
    }
};
