// 575. Distribute Candies
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> hash_set;
        for (auto i : candies)
            hash_set.insert(i);
        return min(hash_set.size(), candies.size() / 2);
    }
};

int main() {
    Solution s;
    int arr[] = {1, 1, 2, 2, 3, 3};
    int cnt = sizeof(arr) / sizeof(int);
    vector<int> candies(arr, arr+cnt);
    cout << s.distributeCandies(candies) << endl;
}