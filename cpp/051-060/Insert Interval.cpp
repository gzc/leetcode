#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
  };
 

bool compareInterval(Interval a, Interval b)
{
    return (a.start<b.start);
}

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        
        vector<Interval> result;
        if(intervals.size() == 0)
        {
            result.push_back(newInterval);
            return result;
        }
        
        for(int i = 0;i < intervals.size(); i++)
        {
            if(i == 0 && newInterval.end < intervals[0].start)
            {
                result.push_back(newInterval);
                result.push_back(intervals[i]);
            }
            else if(i == intervals.size() -1 && newInterval.start > intervals.back().end)
            {
                result.push_back(intervals[i]);
                result.push_back(newInterval);
            }
            else if(newInterval.start > intervals[i].end && newInterval.end < intervals[i+1].start)
            {
                result.push_back(intervals[i]);
                result.push_back(newInterval);
            }
            else if(intervals[i].start > newInterval.end || intervals[i].end < newInterval.start)
                result.push_back(intervals[i]);
            else {
                int index = i;
                Interval now = newInterval;
                do {
                    now.start = min(intervals[index].start, now.start);
                    now.end = max(intervals[index].end, now.end);
                    index++;
                } while(index < intervals.size() && !(intervals[index].start > now.end || intervals[index].end < now.start));
                result.push_back(now);
                i = index-1;
            }
        }
        
        return result;
    }
    
};

int main()
{
    Solution s;
    
    return 0;
}