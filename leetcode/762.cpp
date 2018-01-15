// 762. Prime Number of Set Bits in Binary Representation
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        unordered_set<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int result = 0;
        for (int i = L; i <= R; ++i) {
            int bits = 0;
            for (int n = i; n; n >>= 1)
                bits += n & 1;
            if (primes.count(bits))
                result += 1;
        }      
        return result;
    }
};

int main() {
    Solution s;
    cout << s.countPrimeSetBits(10, 15);
}