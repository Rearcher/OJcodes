// 432. All O(1) Data Structure
#include "leetcode.hpp"
using namespace std;

class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {

    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (!iters.count(key))
            iters[key] = nodes.insert(nodes.begin(), {0, {key}});

        // insert key in next node
        auto next = iters[key], cur = next++;
        if (next == nodes.end() || next->val > cur->val + 1)
            next = nodes.insert(next, {cur->val + 1, {}});
        next->keys.insert(key);
        iters[key] = next;

        // remove key from current node
        cur->keys.erase(key);
        if (cur->keys.empty())
            nodes.erase(cur);
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (!iters.count(key)) return;

        // insert key in prev node
        auto prev = iters[key], cur = prev--;
        iters.erase(key);
        if (cur->val > 1) {
            if (cur == nodes.begin() || prev->val < cur->val - 1) 
                prev = nodes.insert(cur, {cur->val - 1, {}});
            prev->keys.insert(key);
            iters[key] = prev;
        }

        // remove key from current node
        cur->keys.erase(key);
        if (cur->keys.empty())
            nodes.erase(cur);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return nodes.empty() ? "" : *(nodes.rbegin()->keys.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return nodes.empty() ? "" : *(nodes.begin()->keys.begin());
    }

private:
    struct node { int val; unordered_set<string> keys; };
    list<node> nodes;
    unordered_map<string, list<node>::iterator> iters;
};

int main() {

}