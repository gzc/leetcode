/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
    
    int dfs(const map<int, Employee*>& mymap, int id) {
        int sum = mymap.at(id)->importance;
        for (int sub_id : mymap.at(id)->subordinates) {
             sum += dfs(mymap, sub_id);
        }
        return sum;
    }
    
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int, Employee*> mymap;
        for (Employee* employee : employees) {
            mymap[employee->id] = employee;
        }
        return dfs(mymap, id);
    }
};
