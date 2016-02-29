class Solution {
public:
	bool isPowerOfTwo(int n) {
		if(n < 1) return false;
		while(n>1) {
			if(n%2)
				return false;
			else
				n /= 2;
		}
		return true;
	}
}
