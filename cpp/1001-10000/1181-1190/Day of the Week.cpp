class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<int> t {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};  
        year -= (month < 3);  
        int v = (year + year / 4 - year / 100 +  year / 400 + t[month - 1] + day) % 7;  
        if (v == 1) return "Monday";
        if (v == 2) return "Tuesday";
        if (v == 3) return "Wednesday";
        if (v == 4) return "Thursday";
        if (v == 5) return "Friday";
        if (v == 6) return "Saturday";
        return "Sunday";
    }
};
