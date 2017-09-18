/* remove element */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int removeElement(vector<int> &nums, int val) {
		vector<int>::iterator iter = nums.begin();
		for (; iter != nums.end();) {
			if (*iter == val) iter = nums.erase(iter);
			else ++iter;
		}
		return nums.size();
	}
};

int main() {
	std::vector<int> a{1, 2, 2, 3, 2, 4};
	Solution s;

	std::cout << s.removeElement(a, 2) << std::endl;
}
