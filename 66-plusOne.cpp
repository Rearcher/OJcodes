class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		if(digits.empty()) return digits;
		int n=digits.size();
		int carry=0;
		for(int i=n-1; i>=0; i--) {
			if(i==n-1) {
				digits[i] += 1;
				carry = digits[i]/10;
				digits[i] %= 10;
			}
			else {
				digits[i] += carry;
				carry = digits[i]/10;
				digits[i] %= 10;
			}
		}
		if(carry) digits.insert(digits.begin(), 1);
		return digits;
	}
};
