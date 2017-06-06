// 401. Binary Watch
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        vector<int> hours{8, 4, 2, 1};
        vector<int> minutes{32, 16, 8, 4, 2, 1};

        for (int i = 0; i <= num; ++i) {
            vector<int> hour_num = generate(hours, i);
            vector<int> minute_num = generate(minutes, num - i);

            for (int j = 0; j < hour_num.size(); ++j) {
                if (hour_num[j] >= 12) continue;
                for (int k = 0; k < minute_num.size(); ++k) {
                    if (minute_num[k] >= 60) continue;
                    result.push_back(to_string(hour_num[j]) + ":" + 
                        (minute_num[k] < 10 ? "0" + to_string(minute_num[k]) : to_string(minute_num[k])));
                }
            }
        }
        
        return result;
    }

private:
    vector<int> generate(vector<int> nums, int count) {
        vector<int> result;
        generateHelper(nums, count, 0, 0, result);
        return result;
    }

    void generateHelper(vector<int> nums, int count, int pos, int sum, vector<int>& result) {
        if (count == 0) {
            result.push_back(sum);
            return;
        }

        for (int i = pos; i < nums.size(); ++i) {
            generateHelper(nums, count - 1, i + 1, sum + nums[i], result);
        }
    }
};

int main() {
    Solution s;
    vector<string> res = s.readBinaryWatch(1);
    for (string s : res) {
        cout << s << " ";
    }
    cout << "\n";
}