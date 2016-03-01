/* single number */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int> &nums) {
		int ans = 0;
		for (auto num : nums)
			ans ^= num;
		return ans;
	}
};

int main() {
	Solution s;
	vector<int> x{1, 2, 3, 4, 2, 3, 4};
	vector<int> y{1, 1, 2, 2, 3, 3, 4};
	cout << s.singleNumber(x) << endl;
	cout << s.singleNumber(y) << endl;
}
