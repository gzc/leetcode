/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class SummaryRanges {
    
    vector<Interval> vec;
    
public:
    void addNum(int val) {
        //anonymous function
        auto Cmp = [](Interval a, Interval b) { return a.start < b.start; };
        auto it = lower_bound(vec.begin(), vec.end(), Interval(val, val), Cmp);
        int start = val, end = val;
        if(it != vec.begin() && (it-1)->end + 1 >= val) it--;
        while(it != vec.end() && val+1 >= it->start && val-1 <= it->end)
        {
            start = min(start, it->start);
            end = max(end, it->end);
            it = vec.erase(it);
        }
        vec.insert(it,Interval(start, end));
    }

    vector<Interval> getIntervals() {
        return vec;
    }
    
};



/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
