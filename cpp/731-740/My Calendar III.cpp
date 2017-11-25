class MyCalendarThree {
    multiset<pair<int, bool>> myset;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        int level = 0;
        int maxLevel = 1;
        myset.insert({start, true});
        myset.insert({end, false});
        for (const auto& e : myset) {
            if (e.second == true) {
                level++;
            } else {
                level--;
            }
            maxLevel = max(maxLevel, level);
        }
        return maxLevel;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */
