// 380. Insert Delete GetRandom O(1)
#include "leetcode.hpp"
using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {

    }

    bool insert(int val) {
        if (m.count(val)) return false;

        nums.push_back(val);
        m[val] = nums.size() - 1;

        return true;
    }

    bool remove(int val) {
        if (!m.count(val)) return false;

        int last = nums.back();
        m[last] = m[val];
        nums[m[val]] = last;
        nums.pop_back();
        m.erase(val);

        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }

private:
    unordered_map<int, int> m;
    vector<int> nums;
};

int main() {

}