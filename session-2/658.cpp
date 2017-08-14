// 658. Find K Closest Elements
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int index = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int i = index - 1, j = index;
        while (k--) (i < 0 || (j < arr.size() && arr[j] - x < x - arr[i])) ? j++ : i--;
        return vector<int>(arr.begin() + i + 1, arr.begin() + j);
    }
};

int main() {

}