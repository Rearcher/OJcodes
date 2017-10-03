// 690. Employee Importance
#include "leetcode.hpp"
using namespace std;

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

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, vector<int>> m;
        for (Employee* e : employees) {
            vector<int> tmp{e->importance};
            tmp.insert(tmp.end(), e->subordinates.begin(), e->subordinates.end());
            m[e->id] = tmp;
        }
        
        int cnt = 0;
        queue<int> ids;
        ids.push(id);
        while (!ids.empty()) {
            int cur = ids.front();
            ids.pop();

            cnt += m[cur][0];
            for (int i = 1; i < m[cur].size(); ++i)
                ids.push(m[cur][i]);
        }

        return cnt;
    }
};

int main() {
    Employee a, b, c;
    a.id = 1, a.importance = 5, a.subordinates = {2, 3};
    b.id = 2, b.importance = 3;
    c.id = 3, c.importance = 3;

    vector<Employee*> employees;
    employees.push_back(&a);
    employees.push_back(&b);
    employees.push_back(&c);
    
    Solution s;
    cout << s.getImportance(employees, 1) << endl;
}