/* contains duplicate III */
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
	bool containsNearby(vector<int> &nums, int k, int t) {
		set<int> s;
		if (k >= nums.size()) k = nums.size()-1;

		for (int i = 0; i < nums.size(); i++) {
			if (i > k) s.erase(nums[i-k-1]);
				
			// nums[i] - x <= t;
			auto iter = s.lower_bound(nums[i]-t);
			
			// x - nums[i] <= t;
			if (iter != s.end() && *iter-nums[i]<=t) return true;
			
			s.insert(nums[i]);
		}
		return false;
	}
};

int main() {
	vector<int> a{4, 2};
	Solution s;

	cout << s.containsNearby(a, 1, 2) << endl;
}
