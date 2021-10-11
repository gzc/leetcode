class Solution {
    
    vector<string> split(const string &s, char delim) {
        vector<string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            if (item.length() > 0) {
                elems.push_back(item);
            }
        }
        return elems;
    }
    
    string construct(long x, long rightMost) {
        vector<string> ans(4);
		ans[0] = to_string(x & 255); x >>= 8;
		ans[1] = to_string(x & 255); x >>= 8;
		ans[2] = to_string(x & 255); x >>= 8;
		ans[3] = to_string(x);
		int len = 33;
		while (rightMost > 0) {
			len --;
			rightMost /= 2;
		}
		return ans[3] + "." + ans[2] + "." + ans[1] + "." + ans[0] + "/" + to_string(len);
    }
    
public:
    vector<string> ipToCIDR(string ip, int n) {
        vector<string> digits = split(ip, '.');
        long start = stol(digits[0])*256*256*256 + stol(digits[1])*256*256 + stol(digits[2])*256 + stol(digits[3]);
        vector<string> ans;
        
        while (n > 0) {
            long rightMost = start == 0 ? 1 << 30 : start & -start;
            while (rightMost > n) rightMost /= 2;
            ans.push_back(construct(start, rightMost));
            n -= rightMost;
            start += rightMost;
        }
        
        return ans;
    }
};
