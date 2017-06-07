// 551. Student Attendance Record I
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int absent_cnt = 0, late_cnt = 0;
        bool last_late = false;

        for (char c : s) {
            if (c == 'L') {
                if (last_late) {
                    late_cnt += 1;
                    if (late_cnt > 2)
                        return false;
                } else {
                    late_cnt = 1;
                }
                last_late = true;
                continue;
            }

            if (c == 'A') {
                absent_cnt += 1;
            } 

            last_late = false;
        }

        if (absent_cnt > 1) 
            return false;

        return true;
    }
};

int main() {
    Solution s;
    cout << s.checkRecord("PPALLP") << endl;
    cout << s.checkRecord("PPALLL") << endl;
}