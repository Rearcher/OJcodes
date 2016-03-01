/* single number III */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int> &nums) {
		int bits = 0;
		for (auto num : nums)
			bits ^= num;

		bits &= (-bits);
		
		int ans1 = 0, ans2 = 0;
		for (auto num : nums) {
			if ((num & bits) == 0)
				ans1 ^= num;
			else 
				ans2 ^= num;
		}

		return vector<int>{ans1, ans2};
	}
};

int main() {
	Solution s;
	vector<int> x{1, 2, 1, 3, 2, 5};
	vector<int> y = s.singleNumber(x);
	for (auto i : y)
		cout << i << endl;
}
