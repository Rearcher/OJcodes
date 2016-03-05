/* product of array except self */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int> &nums) {
		vector<int> ans(nums.size(), 1);

		for (unsigned int i = 1; i < nums.size(); ++i) {
			ans[i] = ans[i-1] * nums[i-1];
		}

		int right = 1;
		for (int i = nums.size() - 1; i >= 0; --i) {
			ans[i] *= right;
			right *= nums[i];
		}

		return vector<int>(ans);
	}
};

int main() {
	Solution s;
	vector<int> a{1, 2, 3, 4};

	vector<int> b(s.productExceptSelf(a));
	for (auto i : b) cout << i << " ";
}
