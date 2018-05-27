class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        map<int, set<int>> graph;
        map<int, int> idxs;

        for (int i = 0; i < org.size(); i++)
            idxs[org[i]] = i;

        for (int j = 0; j < seqs.size(); j++) {
            vector<int> seq = seqs[j];
            for (int i = 0; i < seq.size(); i++) {
                if (idxs.count(seq[i]) == 0)
                    return false;
                if (i > 0 && idxs[seq[i - 1]] >= idxs[seq[i]])
                    return false;
                graph[seq[i-1]].insert(seq[i]);
            }
        }
        
        if (graph.empty()) return false;

        for (int i = 0; i < org.size() - 1; i++)
            if (graph[org[i]].count(org[i+1]) == 0)
                return false;

        return true;
    }
};
