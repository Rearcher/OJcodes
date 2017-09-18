/* ugly number */
#include <iostream>

class Solution {
public:
	bool isUgly(int num) {
		for (int i = 2; i < 6; i++)
			while (num % i == 0)
				num /= i;
		return num == 1;
	}
};

int main() {
	Solution s;
	int x;
	while(std::cin >> x)
		std::cout << s.isUgly(x) << std::endl;
}
