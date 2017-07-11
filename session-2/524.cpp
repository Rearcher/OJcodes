// 524. Longest Word in Dictionary through Deleting
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), [&](const string& a, const string& b) {
            if (a.size() == b.size())
                return a < b;
            return a.size() > b.size();
        });

        string result;
        for (string to : d) {
            if (canForm(s, to)) {
                result = to;
                break;
            }
        }

        return result;
    }

private:
    bool canForm(string from, string to) {

        int i = 0, j = 0;
        while (i < from.size() && j < to.size()) {
            if (from[i] == to[j]) {
                j++;
                i++;
            } else {
                i++;
            }
        }

        if (j < to.size()) return false;
        return true;
    }
};

int main() {
    vector<string> d{"ale", "apple", "monkey", "plea"};
    string s = "abpcplea";

    Solution solution;
    cout << solution.findLongestWord(s, d) << endl;
}