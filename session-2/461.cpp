// 461. Hamming Distance

#include <iostream>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int result = 0;
        while (x > 0 || y > 0) {
            if ((x & 1) != (y & 1))
                result += 1;
            x >>= 1;
            y >>= 1;
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.hammingDistance(1, 4) << endl;
}