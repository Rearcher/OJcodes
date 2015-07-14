class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> ans;
		int n=s.size(), cnt=words.size();
		if(n<=0 || cnt<=0) return ans;

		unordered_map<string, int> wmap;
		for(auto i:words) wmap[i]++;

		int wl=words[0].size();
		for(int i=0; i<wl; i++) {
			int left=i, count=0;
			unordered_map<string,int> hmap;
			for(int j=i; j<=n-wl; j+=wl) {
				string t = s.substr(j,wl);
				if(wmap.count(t)) {
					hmap[t]++;
					if(hmap[t] <= wmap[t]) count++;
					else {
						while(hmap[t] > wmap[t]) {
							string str = s.substr(left, wl);
							hmap[str]--;
							if(hmap[str] < wmap[str]) count--;
							left += wl;
						}
					}

					if(count==cnt) {
						ans.push_back(left);
						hmap[s.substr(left, wl)]--;
						count--;
						left += wl;
					}
				}
				else {
					hmap.clear();
					count = 0;
					left = j+wl;
				}
			}
		}
		return ans;
	}
};
