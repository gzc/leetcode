class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> toVisit;
        unordered_set<string> dict(bank.begin(), bank.end());
        int dist = 0;
        
        if(!dict.count(end)) return -1;
        
        toVisit.push(start);
        dict.insert(start); dict.insert(end);
        while(!toVisit.empty()) {
            int n = toVisit.size();
            for(int i=0; i<n; i++) {
                string str = toVisit.front();
                toVisit.pop();
                if(str==end) return dist;
                addWord(str, dict, toVisit);
            }
            dist++;
        }
        return -1;
    }
    
    void addWord(string word, unordered_set<string>& dict, queue<string>& toVisit) {
        for(int i=0; i<word.size(); i++) {
            char tmp = word[i];
            for(char c:string("ACGT")) {
                word[i] = c;
                if(dict.count(word)) {
                    toVisit.push(word);
                    dict.erase(word);
                }
            }
            word[i] = tmp;
        }
    }
};
