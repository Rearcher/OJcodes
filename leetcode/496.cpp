// 496. Next Greater Element I
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> s;
        unordered_map<int, int> m;
        for (int num : nums) {
            while (s.size() && s.top() < num) {
                m[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }

        vector<int> result;
        for (int num : findNums) {
            result.push_back(m.count(num) ? m[num] : -1);
        }

        return result;
    }
};

int main() {
    vector<int> v1{4, 1, 2};
    vector<int> v2{1, 3, 4, 2};
    Solution s;

    vector<int> v3 = s.nextGreaterElement(v1, v2);
    for (int n : v3)
        cout << n << " ";
    cout << "\n";
}