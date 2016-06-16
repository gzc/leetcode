class Logger {
    
    map<string, int> mymap;
    
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false. The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if(mymap.count(message) == 0) {
            mymap[message] = timestamp;
            return true;
        }
        int t = mymap[message];
        if(timestamp - t < 10) return false;
        mymap[message] = timestamp;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */
