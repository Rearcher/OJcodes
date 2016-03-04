#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int> &nums) {
		for (unsigned int i = 0; i < nums.size(); i++) {
			if (nums[i] == 0) {
				unsigned int j = i;
				while (++j < nums.size() && nums[j] == 0);
				if (j >= nums.size()) break;

				std::swap(nums[i], nums[j]);
			}
		}
	}

	void moveZeroes_ex(vector<int> &nums) {
		for (unsigned int i = 0, j = 0; i < nums.size(); i++) {
			if (nums[i] != 0) swap(nums[i], nums[j++]);
		}
	}
};

int main() {
	vector<int> a{0, 1, 0, 3, 12};
	Solution s;

	s.moveZeroes(a);

	for (auto i : a)
		cout << i << endl;
}
