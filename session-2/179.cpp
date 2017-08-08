// 179. Largest Number
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (int n : nums) strs.push_back(to_string(n));

        sort(strs.begin(), strs.end(), [&](const string& a, const string& b) {
            string s1 = a + b;
            string s2 = b + a;
            return s1 > s2;
        });

        string result = "";
        for (string str : strs) {
            result.append(str);
        }
        
        if (result[0] == '0') return "0";
        return result;
    }
};

int main() {
    vector<int> nums{3, 30, 34, 5, 9};
    Solution s;
    cout << s.largestNumber(nums) << endl;
}