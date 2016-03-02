/* count primes */
#include <iostream>
#include <vector>

class Solution {
public:
	int countPrimes(int n) {
		std::vector<bool> isPrime(n, true);
		isPrime[0] = isPrime[1] = false;

		for (int i = 2; i * i < n; i++) {
			if (isPrime[i]) {
				for (int j = 2; j * i < n; j++)
					isPrime[j*i] = false;
			}
		}

		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (isPrime[i]) cnt++;
		return cnt;
	}
};

int main() {
	Solution s;
	int x;
	while(std::cin >> x)
		std::cout << s.countPrimes(x) << std::endl;
}
