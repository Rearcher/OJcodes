// 735. Asteriod Collision
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        bool hasCollision = true;
        vector<int> result;

        while (hasCollision) {
            hasCollision = false;
            int i = 0;
            while (i < asteroids.size()) {
                if (i + 1 < asteroids.size()) {
                    if (asteroids[i] > 0 && asteroids[i + 1] < 0) {
                        if (abs(asteroids[i]) > abs(asteroids[i + 1])) {
                            result.push_back(asteroids[i]);
                        } else if (abs(asteroids[i]) < abs(asteroids[i + 1])) {
                            result.push_back(asteroids[i + 1]);
                        }
                        i += 2;
                        hasCollision = true;
                    } else {
                        result.push_back(asteroids[i]);
                        i += 1;
                    }
                } else {
                    result.push_back(asteroids[i]);
                    i += 1;
                }
            }
            asteroids = vector<int>(result);
            result.clear();
        }    
        return asteroids;
    }
};

int main() {
    Solution s;
    vector<int> a{-2, -2, -2, 1};
    vector<int> result = s.asteroidCollision(a);
    for (auto i : result) cout << i << " ";
    cout << "\n";
}