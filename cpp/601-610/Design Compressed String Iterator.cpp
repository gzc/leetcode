class StringIterator {
    string str;
    char current;
    int times;
    int index;
public:
    StringIterator(string compressedString) {
        str = compressedString;
        times = 0;
        index = 0;
    }
    
    char next() {
        if (hasNext()) {
            times--;
            return current;
        }
        return ' ';
    }
    
    bool hasNext() {
        if (times > 0) return true;
        if (index >= str.length()) return false;
        current = str[index++];
        int temp = 0;
        while (index < str.length() && isdigit(str[index])) {
            temp = 10 * temp + (str[index] - '0');
            index++;
        }
        times = temp;
        return true;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */
