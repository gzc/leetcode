class LogSystem {
    vector<pair<int, string>> logs;
public:
    LogSystem() {
        
    }
    
    void put(int id, string timestamp) {
        logs.push_back({id, timestamp});
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        int length = 0;
        if (gra == "Year") {
            length = 4;
        } else if (gra == "Month") {
            length = 7;
        } else if (gra == "Day") {
            length = 10;
        } else if (gra == "Hour") {
            length = 13;
        } else if (gra == "Minute") {
            length = 16;
        } else if (gra == "Second") {
            length = 19;
        }
        
        s = s.substr(0, length);
        e = e.substr(0, length);
        
        vector<int> result;
        for (const auto& ele : logs) {
            string str = ele.second.substr(0, length);
            if (str >= s && str <= e) {
                result.push_back(ele.first);
            }
        }
        return result;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */
