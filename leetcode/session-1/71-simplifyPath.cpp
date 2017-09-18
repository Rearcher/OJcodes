class Solution {
public:
	string simplifyPath(string path) {
		if(path.empty()) return path;
		int i=0;
		string t;
		vector<string> res;
		while(i<path.size()) {
			t.clear();
			if(path[i]=='/') {
				if(res.empty() || (res.back()!="/"&&i!=path.size()-1))
					res.push_back("/");
				while((++i)<path.size() && path[i]!='/')
					t.push_back(path[i]);
				if(t.empty() || t==".") continue;
				if(t==".." && !res.empty()) {
					res.pop_back();
					if(res.empty()) {
						res.push_back("/");
						continue;
					}
					res.pop_back();
					continue;
				}
				res.push_back(t);
			}
		}
		if(res.back()=="/" && res.size()>1) res.pop_back();
		t.clear();
		for(int i=0; i<res.size(); i++)
			t += res[i];
		return t;
	}
};
