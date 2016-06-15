class Solution {
public:
    string rearrangeString(string str, int k) {
        if(k <= 1) return str;
        string res;
    	int len = str.length();
    	map<char, int> mymap;
    	priority_queue< pair<int, char> > mypq;
    	for(char c : str)
    		mymap[c]++;
    	for(auto e : mymap) 
    		mypq.push({e.second, e.first});
    
    	while(!mypq.empty()) {
    		int cnt = min(len, k);
    		vector<pair<int, char>> myvec;
    		for(int i = 0;i < cnt;i++) {
    		    if(mypq.empty()) return "";
    			pair<int, char> mypair = mypq.top();
    			mypq.pop();
    			res.push_back(mypair.second);
    			if(mypair.first > 1) {
    				myvec.push_back({mypair.first-1, mypair.second});
    			}
    		}
    		for(auto e : myvec) mypq.push(e);
    		len -= cnt;
    	}
    	return res;
    }
};
