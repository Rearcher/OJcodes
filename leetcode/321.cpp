// 321. Create Maximum Number
#include "leetcode.hpp"
using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        vector<int> result(k, 0);

        bool init = true;
        for (int i = max(0, k-m); i <= k && i <= n; ++i) {
            vector<int> v1 = maxSubsequence(nums1, i);
            vector<int> v2 = maxSubsequence(nums2, k - i);
            vector<int> tmp = merge(v1, v2, k);

            if (init || toString(tmp) > toString(result)) {
                result = tmp;
                init = false;
            }
        }

        return result;
    }

private:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size(), j = 0;
        vector<int> result(k, 0);
        
        for (int i = 0; i < n; ++i) {
            while (j > 0 && nums[i] > result[j-1] && n - i > k - j) j--;
            if (j < k) result[j++] = nums[i];
        }

        return result;
    }

    vector<int> merge(vector<int>& a, vector<int>& b, int k) {
        vector<int> result(k, 0);

        string str1 = toString(a), str2 = toString(b);
        for (int i = 0, j = 0, r = 0; r < k; ++r)
            result[r] = str1.substr(i) > str2.substr(j) ? a[i++] : b[j++];

        return result;
    }

    string toString(vector<int>& v) {
        stringstream ss;
        for (int n : v) ss << n;
        return ss.str();
    }
};

int main() {
    Solution s;
    vector<int> a{3, 4, 6, 5}, b{9, 1, 2, 5, 8, 3};
    vector<int> result = s.maxNumber(a, b, 5);
    for (int r : result) cout << r << " ";
    cout << "\n";
}
