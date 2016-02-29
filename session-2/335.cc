/* Self Crossing */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isSelfCrossing(vector<int> &x) {
		if (x.size() <= 3) return false;
		for (unsigned int i = 3; i < x.size(); i++) {
			if (x[i] >= x[i-2] && x[i-1] <= x[i-3])
				return true;
		}
		return false;
	}
};

int main() {
	vector<int> x{1, 1, 1, 1};
	Solution s;

	cout <<	s.isSelfCrossing(x) << endl;;
}
