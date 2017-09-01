// 460. LFU Cache
#include "leetcode.hpp"
using namespace std;

class LFUCache {
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
    }
    
    int get(int key) {
        if (!data.count(key)) return -1;

        // remove key from current frequency
        freqToKey[data[key].second].erase(keyToIter[key]);
        data[key].second++;
        // add key to new frequency, update iterator
        freqToKey[data[key].second].push_back(key);
        keyToIter[key] = --freqToKey[data[key].second].end();

        // check current minimum frequency exsits
        if (freqToKey[minFreq].empty())
            minFreq += 1;

        return data[key].first;
    }
    
    void put(int key, int value) {
        if (capacity <= 0) return;

        int val = get(key);
        if (val != -1) {
            data[key].first = value;
            return;
        }

        // remove key with minimum frequency
        if (size >= capacity) {
            int minKey = freqToKey[minFreq].front();
            data.erase(minKey);
            keyToIter.erase(minKey);
            freqToKey[minFreq].pop_front();
            size -= 1;
        }

        // insert new key with frequency 1
        data[key] = {value, 1};
        freqToKey[1].push_back(key);
        keyToIter[key] = --freqToKey[1].end();
        minFreq = 1;
        size += 1;
    }

private:
    int capacity;
    int size;
    int minFreq;

    unordered_map<int, pair<int, int>> data;
    unordered_map<int, list<int>> freqToKey;
    unordered_map<int, list<int>::iterator> keyToIter;
};

int main() {
    LFUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;

    cache.put(3, 3);
    // cout << cache.get(2) << endl;
}