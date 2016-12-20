class Solution {
    
    void split(const std::string &s, char delim, std::vector<std::string> &elems) {
        std::stringstream ss;
        ss.str(s);
        std::string item;
        while (std::getline(ss, item, delim)) {
            elems.push_back(item);
        }
    }

    std::vector<std::string> split(const std::string &s, char delim) {
        std::vector<std::string> elems;
        split(s, delim, elems);
        return elems;
    }
    
    static bool validateV4num(const string& num) {
        if (num.empty() || num.length() > 3) return false;
        for (char c : num)
            if (!isdigit(c))
                return false;
        int v = stoi(num);
        if (v >= 0 && v <= 255 && to_string(v).length() == num.length()) return true;
        return false;
    }
    
    static bool validateV6num(const string& num) {
        if (num.empty() || num.length() > 4) return false;
        for (char c : num) {
            if (isdigit(c)) continue;
            if (c >= 'a' && c <= 'f') continue;
            if (c >= 'A' && c <= 'F') continue;
            return false;
        }
        return true;
    }
    
    string checkV4(const string& IP) {
        vector<string> nums = split(IP, '.');
        if (nums.size() != 4) return "Neither";
        if ( std::all_of(nums.begin(), nums.end(), validateV4num) ) return "IPv4";
        return "Neither";
    }
    
    string checkV6(const string& IP) {
        vector<string> nums = split(IP, ':');
        if (nums.size() != 8) return "Neither";
        if ( std::all_of(nums.begin(), nums.end(), validateV6num) ) return "IPv6";
        return "Neither";
    }
    
public:
    string validIPAddress(string IP) {
        if (!isalnum(IP.back())) return "Neither";
        if (IP.find('.') != std::string::npos) return checkV4(IP);
        else if (IP.find(':') != std::string::npos) return checkV6(IP);
        else return "Neither";
    }
};
