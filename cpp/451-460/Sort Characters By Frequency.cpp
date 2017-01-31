class Solution {
public:
    string frequencySort(string s) {
        map<char,int> freq;
        vector<string> bucket(s.size()+1, "");
        string res;
        
        //count frequency of each character
        for (char c : s) freq[c]++;
        //put character into frequency bucket
        for (const auto& it : freq) {
            int n = it.second;
            char c = it.first;
            bucket[n].append(n, c);
        }
        //form descending sorted string
        for (int i = s.size(); i>0; i--) {
            if (!bucket[i].empty())
                res.append(bucket[i]);
        }
        return res;
    }
};
