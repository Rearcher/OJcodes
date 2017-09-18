// 381. Insert Delete GetRandom(1) - Duplicates allowed
#include "leetcode.hpp"
using namespace std;

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool result = !m.count(val);

        m[val].push_back(nums.size());
        nums.push_back({val, m[val].size() - 1});

        return result;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (!m.count(val)) return false;

        pair<int, int> last = nums.back();
        m[last.first][last.second] = m[val].back();
        nums[m[val].back()] = last;
        m[val].pop_back();

        if (m[val].empty()) m.erase(val);
        nums.pop_back();

        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()].first;
    }

private:
    vector<pair<int, int>> nums;
    unordered_map<int, vector<int>> m;
};

int main() {

}