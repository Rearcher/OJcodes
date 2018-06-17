// 853. Car Fleet
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        vector<pair<double, double>> cars;
        int n = pos.size(), res = 0;
        for (int i = 0; i < n; ++i)
            cars.push_back({(double)pos[i], (double)(target - pos[i]) / speed[i]});
        sort(cars.begin(), cars.end());

        double cur = 0;
        for (int i = n - 1; i >= 0 ; --i)
            if (cars[i].second > cur) {
                cur = cars[i].second;
                res++;
            }
        return res;
    }
};

int main() {
    Solution s;
    int target = 12;
    vector<int> position{4,0,5,3,1,2};
    vector<int> speed{6, 10, 9, 6, 7, 2};
    cout << s.carFleet(target, position, speed) << "\n";
}