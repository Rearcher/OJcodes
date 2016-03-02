/* happy number */
#include <iostream>
#include <unordered_map>

class Solution {
public:
	bool isHappy(int n) {
		std::unordered_map<int, int> hashMap;
		int sum = 0;
		hashMap.insert({n, 1});

		while (n) {
			sum += (n%10) * (n%10);
			n /= 10;

			if (n == 0) {
				if (sum == 1) return true;
				else if (hashMap.find(sum) == hashMap.end()) {
					hashMap.insert({sum, 1});
					n = sum;
					sum = 0;
				} else {
					return false;
				}
			}
		}
	}
};

int main() {
	Solution s;
	int x;
	while(std::cin >> x) {
		std::cout << s.isHappy(x) << std::endl;
	}
}
