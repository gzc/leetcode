class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> visited;
        vector<string> ans;
        
        for (const string& name : names) {
            if (visited.count(name) == 0) {
                ans.push_back(name);
                visited[name]++;
            } else {
                int i = visited[name];
                while (true) {
                    string new_name = name + "(" + to_string(i) + ")";
                    if (visited.count(new_name) == 0) {
                        ans.push_back(new_name);
                        visited[name] = i;
                        visited[new_name]++;
                        break;
                    }
                    i++;
                }
            }
        }
        
        return ans;
    }
};
