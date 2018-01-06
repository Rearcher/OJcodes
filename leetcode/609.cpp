// 609. Find Duplicate File in System
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> m;
        for (const string& path : paths) {
            istringstream input(path);
            string temp, dirname;
            getline(input, dirname, ' ');
            while (getline(input, temp, ' ')) {
                if (temp.length() <= 0) continue;
                int i = 0;
                while (i < temp.length() && temp[i] != '(')
                    i++;
                string filename = dirname + "/" + temp.substr(0, i);
                string content = temp.substr(i);

                if (m.count(content)) {
                    m[content].push_back(filename);
                } else {
                    m[content] = vector<string>{filename};
                }
            }
        }

        vector<vector<string>> result;
        for (const auto& kv : m) {
            if (kv.second.size() > 1)
                result.push_back(kv.second);
        }

        return result;
    }
};

int main() {

}