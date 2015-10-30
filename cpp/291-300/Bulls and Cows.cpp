class Solution {
public:
    string getHint(string secret, string guess) {
        int A(0),B(0);
        map<char, int> mymap1;
        map<char, int> mymap2;
        for(int i = 0;i < secret.length();i++) {
            if(secret[i] == guess[i]) A++;
            else {
                mymap1[secret[i]]++;
                mymap2[guess[i]]++;
            }
        }
        
        for(int i = 0;i <= 9;i++)
            B += min(mymap1['0'+i],mymap2['0'+i]);
        
        return to_string(A)+"A"+to_string(B)+"B";
    }
};