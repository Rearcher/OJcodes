#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		string ans;
		
		while (n) {
			if (n%26 != 0) ans.push_back('A'+n%26-1);
			else {
				ans.push_back('Z');
				n--;
			}

			n /= 26;
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

int main() {
	int x;
	Solution s;
	while (cin >> x)
		cout << s.convertToTitle(x) << endl;
}
