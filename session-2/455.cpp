// 455. Assign Cookies
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0, cnt = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) {
                cnt += 1;
                i += 1;
                j += 1;
            } else {
                while (j < s.size() && g[i] > s[j]) {
                    j++;
                }
                if (j < s.size()) {
                    cnt += 1;
                    i += 1;
                    j += 1;
                }
            }
        }

        return cnt;
    }
};

int main() {
    Solution solution;
    // vector<int> g{1, 2, 3}, s{1, 1};
    vector<int> g{1, 2, 3}, s{3};
    cout << solution.findContentChildren(g, s) << endl;
}