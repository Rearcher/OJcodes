/* power of three */
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
	bool isPower(int n) {
		int maxPower = (int)pow(3, (int)(log(0x7fffffff)/log(3)));
		return n > 0 && maxPower%n==0;
	}
};

int main() {
	int x;
	Solution s;

	while (cin >> x)
		cout << s.isPower(x) << endl;
}
