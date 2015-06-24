class Solution {
public:
	int hammingWeight(uint32_t n) {
		int cnt=0;
		while(n) {
			if(n%2) cnt++;
			n = n/2;
		}
		return cnt;
	}
};
