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
    
    static bool compare(Interval& interval1, Interval& interval2) {
        return interval1.start < interval2.start;
    }
    
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        priority_queue<int, vector<int>, std::greater<int>> myqueue;
        
        for(int i = 0;i < intervals.size();i++)
        {
            if(i == 0) myqueue.push(intervals[i].end);
            
            else {
                int v = myqueue.top();
                if(v <= intervals[i].start) {
                    myqueue.pop();
                }
                myqueue.push(intervals[i].end);
            }
        }
        
        return myqueue.size();
    }
};