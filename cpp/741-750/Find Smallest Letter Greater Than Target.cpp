class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<char>::iterator it = upper_bound(letters.begin(), letters.end(), target);
        if (it == letters.end()) return letters.front();
        return *it;
    }
};




class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (target >= letters.back()) {
            return letters.front();
        }
        int i = 0;
        int j = letters.size() - 1;
        
        while (i < j) {
            int mid = (i + j) / 2;
            if (target < letters[mid]) {
                j = mid;
            } else if (target >= letters[mid]) {
                i = mid + 1;
            }
        }
        
        return letters[i];
    }
};
