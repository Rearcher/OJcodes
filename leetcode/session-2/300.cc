/* longest increasing subsequence */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/* O(n^2) */
	int lengthOfLIS(vector<int> &nums) {
		int n = nums.size(), ans = 0;
		if (n == 1) return 1;

		vector<int> dp(n, 0);
		
		for (int i = 1; i < n; i++) {
			int k = 0;
			for (int j = 0; j < i; j++)
				if (nums[j] < nums[i] && k < dp[j])
					k = dp[j];
			dp[i] = ++k;
			ans = max(ans, dp[i]);
		}

		return ans;
	}

	/* O(nlogn) */
	int lengthOfLIS_ex(vector<int> &nums) {
		vector<int> res;
		for (unsigned int i = 0; i < nums.size(); i++) {
			auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
			if (it == res.end()) res.push_back(nums[i]);
			else *it = nums[i];
		}
		return res.size();
	}
};

int main() {
	Solution s;
	vector<int> x{10, 9, 2, 5, 3, 7, 101, 18};

	cout << s.lengthOfLIS(x) << endl;
	cout << s.lengthOfLIS_ex(x) << endl;
}
