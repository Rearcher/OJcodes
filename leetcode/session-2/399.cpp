// 399. Evaluate Division
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, vector<string>> edges;
        unordered_map<string, double> edgeValues;

        for (int i = 0; i < equations.size(); ++i) {
            string from = equations[i].first;
            string to = equations[i].second;

            if (edges.count(from)) {
                edges[from].push_back(to);
            } else {
                edges[from] = {to};
            }

            if (edges.count(to)) {
                edges[to].push_back(from);
            } else {
                edges[to] = {from};
            }

            edgeValues[from + "->" + to] = values[i];
            edgeValues[to + "->" + from] = 1 / values[i];
        }   

        // for (auto p : edges) {
        //     cout << p.first << ": ";
        //     for (auto s : p.second)
        //         cout << s << " ";
        //     cout << "\n";
        // }

        // cout << "\n";
        // for (auto p : edgeValues) {
        //     cout << p.first << " " << p.second << "\n";
        // }

        vector<double> result;
        for (int i = 0; i < queries.size(); ++i) {
            result.push_back(dfs(edges, edgeValues, queries[i], unordered_set<string>{}));
        }

        return result;
    }

private:
    double dfs(unordered_map<string, vector<string>>& edges, unordered_map<string, double>& edgeValues, pair<string, string> query, unordered_set<string> visited) {
        if (!edges.count(query.first) || !edges.count(query.second)) return -1;
        if (query.first == query.second) return 1;
        if (edgeValues.count(query.first + "->" + query.second)) {
            return edgeValues[query.first + "->" + query.second];
        }

        visited.insert(query.first);
        vector<string> toNodes = edges[query.first];
        for (string node : toNodes) {
            if (visited.count(node)) continue;
            double tmp = dfs(edges, edgeValues, make_pair(node, query.second), visited);
            if (tmp != -1) {
                return edgeValues[query.first + "->" + node] * tmp;
            }
        }

        return -1;
    }
};

int main() {
    Solution s;
    vector<pair<string, string>> equations = {{"x1", "x2"}, {"x2", "x3"}, {"x3", "x4"}, {"x4", "x5"}};
    vector<double> values = {3, 4, 5, 6};
    vector<pair<string, string>> queries = {{"x1", "x5"}, {"x5", "x2"}, {"x2", "x4"}, {"x2", "x2"}, {"x2", "x9"}, {"x9", "x9"}};
    // vector<pair<string, string>> queries = {{"x1", "x5"}};f

    vector<double> result = s.calcEquation(equations, values, queries);
    for (auto r : result) {
        cout << r << " ";
    }
    cout << "\n";
    
    return 0;
}