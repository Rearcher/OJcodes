/* maxmium product subarray */
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
	int maxProduct(vector<int> &nums) {
		if (nums.empty()) return 0;

		int maxProduct = nums[0];
		int minProduct = nums[0];
		int maxRes = nums[0];

		for (unsigned int i = 1; i < nums.size(); i++) {
			if (nums[i] >= 0) {
				maxProduct = max(maxProduct * nums[i], nums[i]);
				minProduct = min(minProduct * nums[i], nums[i]);
			} else {
				int temp = maxProduct;
				maxProduct = max(minProduct * nums[i], nums[i]);
				minProduct = min(temp * nums[i], nums[i]);
			}
			maxRes = max(maxRes, maxProduct);
		}
		return maxRes;
	}

	int maxProduct_ex(vector<int> &nums) {
		if (nums.size() == 1) return nums[0];

		int positiveMax, negativeMax, res;
		positiveMax = negativeMax = res = 0;

		for (auto num : nums) {
			if (num < 0) swap(positiveMax, negativeMax);
			positiveMax = max(positiveMax * num, num);
			negativeMax = min(negativeMax * num, num);
			res = max(positiveMax, res);
		}
		
		return res;
	}
};

int main() {
	Solution s;
	vector<int> a{-2, 3, -2, 4, -2};
	cout << s.maxProduct_ex(a) << endl;
}
