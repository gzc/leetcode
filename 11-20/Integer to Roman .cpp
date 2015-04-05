#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    
    string intToRoman(int num) {
        
        string m[] = {"",
                    "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "",
                    "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC", "",
                    "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM", "",
                    "M", "MM", "MMM"};
        
        return m[num/1000+30] + m[(num/100)%10+20] + m[(num/10)%10+10] + m[num%10];
        
    }
    
};

int main()
{
    Solution s;
    cout << s.intToRoman(3333);
}