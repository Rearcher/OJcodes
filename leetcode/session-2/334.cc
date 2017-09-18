/* Increasing Triplet Subsequence */
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
	bool increasingTriplet(vector<int> &nums) {
		int c1 = INT_MAX, c2 = INT_MAX;
		for (int num : nums) {
			if (num <= c1) {
				c1 = num;
			} else if (num <= c2) {
				c2 = num;
			} else {
				return true;
			}
		}
		return false;
	}
};

int main() {
	vector<int> x{1, 2, 3, 4, 5};
	Solution s;
	cout << s.increasingTriplet(x) << endl;
}
