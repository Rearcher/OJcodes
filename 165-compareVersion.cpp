class Solution {
public: 
	int str_to_int(string s) {
		int sum=0;
		for(int i=0; i<s.size(); i++) {
			sum = sum*10 + (s[i]-'0');
		}
		return sum;
	}

	int compareVersion(string version1, string version2) {
		int start1=0, start2=0;
		int pos1=0, pos2=0;
		while(true) {
			for(int i=start1; i<version1.size() && version1[i]!='.'; i++, pos1++);
			for(int i=start2; i<version2.size() && version2[i]!='.'; i++, pos2++);
			string s1 = version1.substr(start1, pos1-start1);
			string s2 = version2.substr(start2, pos2-start2);
			if(str_to_int(s1) > str_to_int(s2)) return 1;
			else if(str_to_int(s1) < str_to_int(s2)) return -1;
			start1 = ++pos1;
			start2 = ++pos2;
			if(start1>=version1.size() && start2>=version2.size()) break;
			else if(start1>=version1.size() && start2<version2.size()) {
				while(true) {
					for(int i=start2; i<version2.size() && version2[i]!='.'; i++, pos2++);
					s2 = version2.substr(start2, pos2-start2);
					if(str_to_int(s2)>0) return -1;
					start2 = ++pos2;
					if(start2 >= version2.size()) break;
				}
				return 0;
			}
			else if(start1<version1.size() && start2>=version2.size()) {
				while(true) {
					for(int i=start1; i<version1.size() && version1[i]!='.'; i++, pos1++);
					s1 = version1.substr(start1, pos1-start1);
					if(str_to_int(s1)>0) return 1;
					start1 = ++pos1;
					if(start1 >= version1.size()) break;
				}
				return 0;

			}
		}
		return 0;
	}
};
