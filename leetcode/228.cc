/* summary ranges */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> summaryRanges(vector<int> &nums) {
		if (nums.empty()) return vector<string>();
		if (nums.size() == 1) return vector<string>{to_string(nums[0])};
		
		vector<string> ans;
		
		int begin = nums[0], end;
		int prev = begin;
		for (unsigned int i = 1; i < nums.size(); ++i) {
			if (nums[i] == prev + 1) {
				prev = nums[i];
				if (i + 1 == nums.size()) {
					end = prev;
					if (begin != end) ans.push_back(to_string(begin) + "->" + to_string(end));
					else ans.push_back(to_string(begin));

					prev = begin = nums[i];
				}
			} else {
				end = prev;
				if (begin != end) ans.push_back(to_string(begin) + "->" + to_string(end));
				else ans.push_back(to_string(begin));
				prev = begin = nums[i];
			}
		}
		if (end < begin) ans.push_back(to_string(begin));

		return vector<string>(ans);
	}
};

int main() {
	Solution s;
	vector<int> a{0, 1};

	vector<string> ans = s.summaryRanges(a);
	for (auto s : ans) cout << s << endl;
	return 0;
}
