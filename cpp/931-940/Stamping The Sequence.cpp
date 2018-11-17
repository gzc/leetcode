class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
      vector<int> res;
      int total_stamp = 0, turn_stamp = -1;
      while (turn_stamp != 0) {
          turn_stamp = 0;
          for (int sz = stamp.size(); sz > 0; --sz) 
              for (int i = 0; i <= stamp.size() - sz; ++i) {
                  string new_stamp = string(i, '*') + stamp.substr(i, sz) + string(stamp.size() - sz - i, '*');
                  size_t pos = target.find(new_stamp);
                  while (pos != string::npos) {
                      res.push_back(pos);
                      turn_stamp += sz;
                      fill(begin(target) + pos, begin(target) + pos + stamp.size(), '*');
                      pos = target.find(new_stamp);
                  }
              }
          total_stamp += turn_stamp;
      }
      reverse(begin(res), end(res));
      return total_stamp == target.size() ? res : vector<int>();
    }
};
