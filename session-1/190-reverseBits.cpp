class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		vector<int> bits;
		while(n) {
			bits.push_back(n%2);
			n /= 2;
		}
		int len=bits.size();
		uint32_t ans=0, mul=(1<<(32-len));
		for(int i=len-1; i>=0; i--) {
			ans += mul*bits[i];
			mul *= 2;
		}
		return ans;
	}
};
