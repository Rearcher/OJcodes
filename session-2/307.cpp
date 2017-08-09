// 307. Range Sum Query - Mutable
#include "leetcode.hpp"
using namespace std;

class NumArray {
public:
    NumArray(vector<int> nums) {
        this->num = nums;
        sum = vector<int>(nums.size() + 1, 0);

        for (int i = 0; i < num.size(); ++i)
            updateBIT(i, num[i]);
        
    }

    void update(int i, int val) {
        int add = val - num[i];
        num[i] = val;
        updateBIT(i, add);
    }

    int sumRange(int i, int j) {
        return getSum(j) - getSum(i-1);
    }

private:
    int lowbit(int x) {
        return x&(-x);
    }

    int getSum(int i) {
        int result = 0;
        i += 1;
        while (i > 0) {
            result += sum[i];
            i -= lowbit(i);
        }
        return result;
    }

    void updateBIT(int i, int val) {
        i += 1;
        while (i < sum.size()) {
            sum[i] += val;
            i += lowbit(i);
        }
    }

    vector<int> sum;
    vector<int> num;
};

int main() {
    vector<int> nums{1, 3, 5};
    NumArray test(nums);

    cout << test.sumRange(0, 2) << endl;
    test.update(1, 2);
    cout << test.sumRange(0, 2) << endl;
}