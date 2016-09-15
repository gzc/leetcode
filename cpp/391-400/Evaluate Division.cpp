class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> query) {
        unordered_map<string, int> varID; // map var name to its ID 
        vector<int> par;                  // par[v2]==v1 ;  v1 is v2's parent
        vector<double> parEq;             // parEq[v2]==t ; v1 is t times of v2 

        for (int i=0; i<equations.size(); i++) { // process equations
            const string& v1Name = equations[i].first;
            const string& v2Name = equations[i].second;
            double x = values[i]; // v1 is x times of v2
            int v1, v2;
            if (varID.count(v1Name)==0) { //new variable
                v1 = par.size();
                par.push_back(v1); //par[v1]==v1, v1 is itself's parent
                parEq.push_back(1); 
                varID[v1Name] = v1;
            } else v1 = varID[v1Name];
            if (varID.count(v2Name)==0) {
                v2 = par.size();
                par.push_back(v2);  
                parEq.push_back(1);
                varID[v2Name] = v2; 
            } else  v2 = varID[v2Name];

            double t1, t2;
            int r1 = findRoot(par, parEq, v1, t1); //r1 is t1 times of v1
            int r2 = findRoot(par, parEq, v2, t2); //r2 is t2 times of v2
            par[r2] = r1;
            parEq[r2] = t1 * x / t2;           //do simple math here
        }

        vector<double> res;
        for (const auto& q : query) {
            int v1, v2;
            if (varID.count(q.first)==1 && varID.count(q.second)==1 ) {
                v1 = varID[q.first];
                v2 = varID[q.second];
            } else {
                res.push_back(-1);
                continue;
            }
            double t1, t2;
            int r1 = findRoot(par, parEq, v1, t1); //r1 is t1 times of v1
            int r2 = findRoot(par, parEq, v2, t2); //r2 is t2 times of v2
            if (r1 != r2) res.push_back(-1);
            else res.push_back(t2/t1);
        }
        return res;
    }
    
    int findRoot(vector<int>& par, vector<double>& parEq, int v, double& t) {
        t = 1;
        while (v != par[v]) {
            // path compression
            parEq[v] = parEq[v] * parEq[par[v]];
            par[v] = par[par[v]];
            // climb up
            t *= parEq[v];
            v = par[v];
        }
        return v;
    }
};
