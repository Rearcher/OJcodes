// 670. Maximum Swap
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        vector<int> pos(str.size());
        int lastPos = str.size() - 1;

        for (int i = str.size() - 1; i >= 0; --i) {
            if (str[i] > str[lastPos]) lastPos = i;
            pos[i] = lastPos;
        }

        for (int i = 0; i < str.size(); ++i) {
            if (str[i] != str[pos[i]]) {
                swap(str[i], str[pos[i]]);
                break;
            }
        }

        return stoi(str);
    }
};

int main() {
    Solution s;
    cout << s.maximumSwap(2736) << endl;
}