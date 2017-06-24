// 503. Next Greater Element II
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result(nums.size(), -1);
        stack<int> st;
        for (int i = nums.size() - 1; i >= 0; --i)
            st.push(i);

        for (int i = nums.size() - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                result[i] = nums[st.top()];
            }
            st.push(i);
        }

        return result;
    }
};

int main() {
    vector<int> nums{1, 2, 1};
    Solution s;
    vector<int> result = s.nextGreaterElements(nums);

    for (int n : result)
        cout << n << " ";
    cout << "\n";
}