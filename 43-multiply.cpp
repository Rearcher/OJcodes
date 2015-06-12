class Solution {
public:
	string multiply(string num1, string num2) {
		if(num1=="0" || num2=="0") return "0";
		if(num1.size()<num2.size()) {
			string temp = num1;
			num1 = num2;
			num2 = temp;
		}
		int len = num1.size()+num2.size();	
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		vector<int> t, f;

		for(int i=0; i<num2.size(); i++) {
			int mul = num2[i]-'0';
			int carry = 0;
			t.clear();
			for(int j=0; j<num1.size(); j++) {
				int bit = mul*(num1[j]-'0')+carry;
				t.push_back(bit%10);
				carry = bit/10;
			}
			if(carry) t.push_back(carry);
			carry = 0;
			int k=0;
			for(int j=i; j<f.size(); j++, k++) {
				int bit = f[j]+t[k]+carry;
				f[j] = bit%10;
				carry = bit/10;
			}
			while(k<t.size()) {
				int bit = t[k++]+carry;
				f.push_back(bit%10);
				carry = bit/10;
			}
			if(carry) f.push_back(carry);
		}

		string res;
		for(int i=f.size()-1; i>=0; i--) 
			res.push_back('0'+f[i]);

		return res;
	}
};
