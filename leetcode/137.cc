/* single number II */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int> &nums) {
		int ones = 0, twos = 0, threes = 0;
		for (auto num : nums) {
			twos |= ones & num;
			ones ^= num;
			threes = ones & twos;
			ones &= ~threes;
			twos &= ~threes;
		}
		return ones;
	}
};

int main() {
	Solution s;
	vector<int> x{1, 1, 1, 2, 2, 2, 3};
	vector<int> y{1, 2, 2, 2, 3, 3, 3};
	cout << s.singleNumber(x) << endl;
	cout << s.singleNumber(y) << endl;
}
