// 756. Pyramid Transition Matrix
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, unordered_set<string>> table;
        for (string s : allowed)
            table[s.substr(0, 2)].insert(s.substr(2));

        vector<string> pyramid{bottom};
        unordered_set<string> visited;
        string row = "";
        int N = bottom.size(); 

        return dfs(pyramid, table, visited, row, N - 1, 0);
    }

private:
    bool dfs(vector<string>& pyramid, unordered_map<string, unordered_set<string>>& table, unordered_set<string>& visited, 
             string row, int layer, int idx) {
        if (layer == 1 && idx == 1) {
            return true;
        } else if (idx == layer) {
            if (visited.count(row)) return false;
            visited.insert(row);
            pyramid.push_back(row);
            bool res = dfs(pyramid, table, visited, "", layer - 1, 0);
            pyramid.pop_back();
            return res;
        } else {
            string key = pyramid.back().substr(idx, 2);
            if (!table.count(key)) return false;

            unordered_set<string> candidates = table[key];
            for (string c : candidates) {
                if (dfs(pyramid, table, visited, row + c, layer, idx + 1))
                    return true;
            }
            return false;
        }
    }
};

int main() {
    Solution s;
    vector<string> allowed{"XXX", "XXY", "XYX", "XYY", "YXZ"};
    cout << s.pyramidTransition("XXYX", allowed) << endl;
}