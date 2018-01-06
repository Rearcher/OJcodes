// 681. Next Closest Time
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    string nextClosestTime(string time) {
        char min = '9', max = '0';
        for (int i = 0; i < 5; ++i) {
            if (i == 2) continue;
            if (time[i] < min) min = time[i];
            if (time[i] > max) max = time[i];
        }

        for (int i = 4; i >= 0; --i) {
            if (i == 2) continue;

            char c = time[i];
            for (int j = 0; j < 5; ++j) {
                if (j == 2 || j == i) continue;
                if (time[j] > time[i]) {
                    if (c == time[i]) c = time[j];
                    else if (time[j] < c) c = time[j];
                }
            }
            if (c != time[i]) {
                if (i == 4) {
                    time[i] = c;
                    return time;
                } else if (i == 3) {
                    if (c >= '0' && c <= '5') {
                        time[i] = c;
                        time[4] = min;
                        return time;
                    }
                } else if (i == 1) {
                    if (time[0] <= '1') {
                        time[i] = c;
                        time[3] = time[4] = min;
                        return time;
                    } else if (c >= '0' && c <= '3') {
                        time[i] = c;
                        time[3] = time[4] = min;
                        return time;
                    }
                } else if (i == 0) {
                    if (c >= '0' && c <= '2') {
                        time[i] = c;
                        time[1] = time[3] = time[4] = min;
                        return time;
                    }
                }
            }
        }

        string result(2, min);
        return result + ":" + result;
    }
};

int main() {
    Solution s;
    cout << s.nextClosestTime("22:23") << endl;
}