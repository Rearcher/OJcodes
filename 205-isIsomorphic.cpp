class Solution {
public:
	bool isIsomorphic(string s, string t) {
		map<char,char> hmap1,hmap2;
		for(int i=0; i<s.size(); i++) {
			if(hmap1.find(s[i])==hmap1.end()) { 
				if(hmap2.find(t[i])==hmap2.end()) {
					hmap1[s[i]] = t[i]; 
					hmap2[t[i]] = '0';
				}
				else return false;
			}
			else if(t[i]!=hmap1[s[i]]) return false;		
		}
		return true;
	}
};
