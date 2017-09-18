// 456. 132 Pattern
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int s3 = INT_MIN;
        stack<int> st;

        for (int i = nums.size() - 1; i >= 0; --i) {
            int num = nums[i];
            if (num < s3) return true;
            else {
                while (!st.empty() && num > st.top()) {
                    s3 = st.top();
                    st.pop();
                }
            }
            st.push(num);
        }

        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums{-1, 3, 2, 0};
    cout << s.find132pattern(nums) << endl;
}