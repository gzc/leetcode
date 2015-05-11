class Solution {
    
    
public:
    bool isScramble(string s1, string s2) {
        // Note: The Solution object is instantiated only once.
    	if(s1.length() != s2.length()) return false;
		if(s1 == s2) return true;

		int A[26] = {0};
		for(int i = 0; i < s1.length(); i++)
			++A[s1[i]-'a'];

		for(int j = 0; j < s2.length(); j++)
			--A[s2[j]-'a'];

		for(int k = 0; k < 26; k++)
			if(A[k] != 0) return false;

        for(int i = 1; i < s1.length(); i++)
		{
			bool result = isScramble(s1.substr(0,i), s2.substr(0,i)) 
				&& isScramble(s1.substr(i), s2.substr(i));
			result = result || (isScramble(s1.substr(0,i), s2.substr(s2.length()-i, i))
				&& isScramble(s1.substr(i), s2.substr(0,s2.length()-i)));
			if(result) return true;
		}
		return false;
    }
};
