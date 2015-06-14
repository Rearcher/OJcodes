class Solution {
public:
	string addBinary(string a, string b) {
		if(a.empty()) return b;
		else if(b.empty()) return a;

		int len_a=a.size(), len_b=b.size();
		int i=len_a-1, j=len_b-1;
		string ans;
		int carry=0;
		while(i>=0 && j>=0) {
			int sum;
			if(a[i]=='0') {
				sum = carry+(b[j]-'0');
				carry = sum/2;
				sum %= 2;
			}
			else {
				if(b[j]=='0') {
					sum = carry+1;
					carry = sum/2;
					sum %= 2;
				}
				else {
					sum = carry+2;
					carry = sum/2;
					sum %= 2;
				}
			}
			if(sum==0) ans.push_back('0');
			else ans.push_back('1');
			
			i--; j--;
		}
		while(i>=0) {
			int sum;
			if(a[i]=='0') {
				sum = carry;
				carry = sum/2;
				sum %= 2;
			}
			else {
				sum = 1+carry;
				carry = sum/2;
				sum %= 2;
			}
			if(sum==0) ans.push_back('0');
			else ans.push_back('1');
			i--;
		}
		while(j>=0) {
			int sum;
			if(b[j]=='0') {
				sum = carry;
				carry = sum/2;
				sum %= 2;
			}
			else {
				sum = 1+carry;
				carry = sum/2;
				sum %= 2;
			}
			if(sum==0) ans.push_back('0');
			else ans.push_back('1');
			j--;
		}
		if(carry) ans.push_back('1');
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
