class Solution {
public:
    int getMinSwaps(string num, int k) {
        string copy = num;
        while (k > 0) {
            std::next_permutation(begin(copy), end(copy));
            k--;
        }
        
        int res = 0;
        for (int i = 0; i < num.length(); i++) {
            if (num[i] == copy[i]) continue;
            
            int j = i + 1;
            for (; j < copy.length(); j++) {
                if (num[i] == copy[j]) {
                    break;
                }
            }
            res += (j - i);
            copy = copy.substr(0, i) + copy[j] + copy.substr(i, j - i) + copy.substr(j + 1); 
        }
        
        return res;
    }
};
