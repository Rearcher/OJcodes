class Solution {
public:
	int trailingZeroes(int n) {
		int ans{0}, x{5};
		while(n>=x) {
			ans += n/x;
			if(x >= INT_MAX/5) break;
			x *= 5;
		}
		return ans;
	}
};
