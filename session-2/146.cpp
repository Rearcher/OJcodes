// 146. LRU Cache
#include "leetcode.hpp"
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto iter = keyToIter.find(key);
        if (iter == keyToIter.end()) return -1;

        dataList.splice(dataList.begin(), dataList, iter->second);
        return iter->second->second;
    }
    
    void put(int key, int value) {
        auto iter = keyToIter.find(key);
        if (iter != keyToIter.end()) {
            dataList.splice(dataList.begin(), dataList, iter->second);
            iter->second->second = value;
            return;
        }

        if (keyToIter.size() == capacity) {
            int deleteKey = dataList.back().first;
            dataList.pop_back();
            keyToIter.erase(deleteKey);
        }

        dataList.emplace_front(key, value);
        keyToIter[key] = dataList.begin();
    }

private:
    unordered_map<int, list<pair<int, int>>::iterator> keyToIter;
    list<pair<int, int>> dataList;
    int capacity;
};