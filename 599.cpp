// 599. Minimum Index Sum of Two Lists
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> m1;
        for (int i = 0; i < list1.size(); ++i) {
            m1[list1[i]] = i;
        }

        int cnt = INT_MAX;
        unordered_map<int, vector<string>> m2;
        for (int i = 0; i < list2.size(); ++i) {
            if (m1.count(list2[i])) {
                int sum = m1[list2[i]] + i;
                if (m2.count(sum)) {
                    m2[sum].push_back(list2[i]);
                } else {
                    m2[sum] = vector<string>{list2[i]};
                }
                cnt = min(cnt, sum);
            }
        }

        return m2[cnt];
    }
};

int main() {
    Solution s;
    vector<string> list1{"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> list2{"KFC", "Shogun", "Burger King"};
    vector<string> result = s.findRestaurant(list1, list2);
    for (auto i : result)
        cout << i << " ";
    cout << endl;
}