class Solution {
public:
	vector<string> anagrams(vector<string>& strs) {
		vector<string> res;
		unordered_map<string, vector<int>> hmap;
		for(int i=0; i<strs.size(); i++) {
			string t=strs[i];
			sort(t.begin(), t.end());
			hmap[t].push_back(i);
		}
		for(auto it=hmap.begin(); it!=hmap.end(); it++) {
			if(it->second.size() > 1) {
				for(int i=0; i<it->second.size(); i++)
					res.push_back(strs[it->second[i]]);
			}
		}
		return res;
	}
};
