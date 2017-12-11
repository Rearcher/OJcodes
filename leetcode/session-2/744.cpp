// 744. Find Smallest Letter Greater Than Target
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (letters.back() <= target) return letters[0];
        int lo = 0, hi = letters.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (letters[mid] <= target) lo = mid + 1;
            else hi = mid;
        }
        return letters[lo];    
    }
};

int main() {
    Solution s;
    vector<char> letters{'c', 'f', 'j'};
    cout << s.nextGreatestLetter(letters, 'j') << endl;
}