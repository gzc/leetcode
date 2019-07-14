class Solution {
    
    vector<int> ans;
    
    map<string, vector<int>> skill_to_ppl;
    
    bool dfs(int need_skills, int n, vector<bool>& used, map<string, bool>& skills_picked, const vector<vector<string>>& people) {
        if (need_skills == 0) {
            for (int i = 0; i < used.size(); i++) {
                if (used[i]) {
                    ans.push_back(i);
                }
            }
            return true;
        }
        if (n == 0) return false;
        
        for (auto& it : skills_picked) {
            if (it.second == false) {
                // we only focus on this skill.
                const string& skill = it.first;
                vector<int>& ppl_index = skill_to_ppl[skill];
                for (int k : ppl_index) {
                    if (used[k]) continue;
                    
                    used[k] = true;
                    const vector<string>& current_person_skills = people[k];
                    int new_skills = 0;
                    vector<string> new_skill_vec;
                    for (const string& current_person_skill : current_person_skills) {
                        if (!skills_picked[current_person_skill]) {
                            skills_picked[current_person_skill] = true;
                            new_skills++;
                            new_skill_vec.push_back(current_person_skill);
                        }
                    }
                    if (dfs(need_skills - new_skills, n-1, used, skills_picked, people)) return true;
                    
                    for (const string& new_skill : new_skill_vec) {
                        skills_picked[new_skill] = false;
                    }
                    used[k] = false;
                }
                
                return false;
            }
        }
        
        return false;
    }
    
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        for (int i = 0; i < people.size(); i++) {
            for (const string& skill : people[i]) {
                skill_to_ppl[skill].push_back(i);
            }
        }
        
        map<string, bool> skills_picked;
        for (const string& req_skill : req_skills) {
            skills_picked[req_skill] = false;
        }
        
        for (int i = 1; i <= req_skills.size(); i++) {
            vector<bool> used(people.size(), false);
            if (dfs(req_skills.size(), i, used, skills_picked, people)) {
                return ans;
            }
        }
        
        return vector<int>();
    }
};
