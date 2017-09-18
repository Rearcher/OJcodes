/* add digits */
#include <iostream>
using namespace std;

class Solution {
public:
	int addDigits(int num) {
		int ans = num - (num - 1) / 9 * 9;
		return ans;
	};
};

int main() {
	int x;
	Solution s;
	while (cin >> x)
		cout << s.addDigits(x) << endl; 
}
