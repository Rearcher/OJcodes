class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if(strs.size()==0) return "";
		else if(strs.size()==1) return strs[0]; //special conditions
		
		int minlen=strs[0].size();				//find the smallest length
		for(int i = 1; i < strs.size(); i++) {
			if(strs[i].length() < minlen) 
				minlen = strs[i].length();
		}

		string res = "";
		for(int i = 0; i < minlen; i++) {
			int j;
			for(j = 0; j < strs.size()-1 && strs[j][i]==strs[j+1][i]; j++);
			if(j == strs.size()-1) res += strs[0][i];
			else break;
		}
		return res;
	}
}
