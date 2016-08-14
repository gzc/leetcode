/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s.empty()) {
            return NestedInteger();
        }
        if (isdigit(s[0]) || s[0] == '-') {
            return NestedInteger(stoi(s));
        }
        s = s.substr(1, s.length()-2);
        NestedInteger result;
        int i(0);
        while (i < s.length()) {
            int j = i;
            int counter(0);
            while (j < s.length()) {
                if (s[j] == '[') {
                    counter++;
                } else if (s[j] == ']') {
                    counter--;
                } else if (s[j] == ',') {
                    if (counter == 0) {
                        result.add(deserialize(s.substr(i, j-i)));
                        break;
                    }
                }
                j++;
            }
            if (j >= s.length()) {
                result.add(deserialize(s.substr(i)));
                break;
            }
            i = j+1;
        }
        return result;
    }
};
