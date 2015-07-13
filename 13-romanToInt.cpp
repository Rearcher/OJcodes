class Solution {
public:
	int romanToInt(string s) {
		map<char,int> hmap;
		hmap.insert(pair<char,int>('I', 1));
		hmap.insert(pair<char,int>('V', 5));
		hmap.insert(pair<char,int>('X', 10));
		hmap.insert(pair<char,int>('L', 50));
		hmap.insert(pair<char,int>('C', 100));
		hmap.insert(pair<char,int>('D', 500));
		hmap.insert(pair<char,int>('M', 1000));

		int ans=0;
		for(int i=0; i<s.size(); i++) {
			if(!i) ans += hmap[s[i]];
			else {
				if(hmap[s[i]]>hmap[s[i-1]])
					ans += (hmap[s[i]]-2*hmap[s[i-1]]);
				else
					ans += hmap[s[i]];
			}
		}
		return ans;
	}
}
