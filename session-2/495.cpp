// 495. Teemo Attacking
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;
        if (timeSeries.size() == 1) return duration;

        int result = 0, endTime = timeSeries[0] + duration - 1;
        for (int i = 1; i < timeSeries.size(); ++i) {
            if (timeSeries[i] > endTime) {
                result += duration;
            } else {
                result += duration - (endTime - timeSeries[i] + 1);
            }
            endTime = timeSeries[i] + duration - 1;
        }

        return result + duration;
    }
};

int main() {

}
