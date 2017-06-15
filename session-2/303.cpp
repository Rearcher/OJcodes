// 303. Range Sum Query - Immutable
#include "leetcode.hpp"
using namespace std;

class NumArray {
public:
    NumArray(vector<int> nums) {
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] += nums[i-1];
        }
        a = nums;
    }

    int sumRange(int i, int j) {
        if (i == 0) return a[j];
        return a[j] - a[i-1];
    }   

private:
    vector<int> a;
};

int main() {
    NumArray s(vector<int>{-2, 0, 3, -5, 2, -1});
    cout << s.sumRange(0, 2) << "\n";
    cout << s.sumRange(2, 5) << "\n";
    cout << s.sumRange(0, 5) << "\n";
}
