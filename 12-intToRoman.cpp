class Solution {
public:
	string intToRoman(int num) {
		if(!num) return "";

		string ans="";
		int i=num/1000;
		while(i--) ans += "M";
	
	}
}
