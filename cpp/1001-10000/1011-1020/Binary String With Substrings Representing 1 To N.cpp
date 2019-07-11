class Solution {
public:
    bool queryString(string S, int N) {
        for (int i = N; i >= 1; i--) {
            int number = i;
            string str_num = "";
		
            // Convert the number to string
            while(number!=0) {
                str_num += number%2 + '0';
                number = number/2;
            }
        
            reverse(str_num.begin(), str_num.end());
            if(S.find(str_num)==string::npos) 
                return false;
        }
    
        return true;
    }
};
