class PhoneDirectory {
    bool *used;
    queue<int> avaliable;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        for(int i = 0;i < maxNumbers;i++) {
            avaliable.emplace(i);
        }
        used = new bool[maxNumbers];
        memset(used, false, maxNumbers);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (!avaliable.empty()) {
            int value = avaliable.front();
            avaliable.pop();
            used[value] = true;
            return value;
        }
        return -1;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return !used[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (used[number]) {
            used[number] = false;
            avaliable.emplace(number);
        }
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
