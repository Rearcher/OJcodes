/* contains duplicate II */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> hashMap;
        for (int i = 0; i < nums.size(); i++) {
            if (hashMap.find(nums[i]) == hashMap.end()) {
                hashMap[nums[i]] = std::move(vector<int> {i});
            } else {
				if (i - hashMap[nums[i]].back() <= k) return true;
                hashMap[nums[i]].push_back(i);
            }
        }
        return false;
    }

	bool contains_ex(vector<int> &nums, int k) {
		if (k <= 0) return false;
		if (k >= nums.size()) k = nums.size() - 1;

		unordered_set<int> s;
		for (int i = 0; i < nums.size(); i++) {
			if (i > k) s.erase(nums[i-k-1]);
			if (s.find(nums[i]) != s.end()) return true;
			s.insert(nums[i]);
		}
		return false;
	}
};

int main() {
	Solution s;
	vector<int> a{1, 2, 3, 4, 5, 6, 1};

	cout << s.containsNearbyDuplicate(a, 6) << endl;
}
