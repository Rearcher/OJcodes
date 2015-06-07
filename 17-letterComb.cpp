class Solution {
public:
	void backtracking(vector<vector<char>>& table, vector<string> &res, string temp, int index, string digits) {
		if(index == digits.length())
			res.push_back(temp);
		else
			for(int i = 0; i < table[digits[index]-'0'].size(); i++) {
				local.push_back(table[digits[index]-'0'][i]);
				backtracking(table, res, temp, index+1, digits);
				local.pop_back();
			}
		return;
	}

	vector<string> letterCombinations(string digits) {
		vector<string> res;
		if(digits.length()==0) return res;

		string temp;
		vector<vector<char>> table(2, vector<char>());	//0 and 1
		table.push_back(vector<char>{'a','b','c'});		//2
		table.push_back(vector<char>{'d','e','f'});		//3
		table.push_back(vector<char>{'g','h','i'});		//4
		table.push_back(vector<char>{'j','k','l'});		//5
		table.push_back(vector<char>{'m','n','o'});		//6
		table.push_back(vector<char>{'p','q','r','s'});	//7
		table.push_back(vector<char>{'t','u','v'});		//8
		table.push_back(vector<char>{'w','x','y','z'});	//9

		backtracking(table, res, temp, 0, digits);
		return res;
	}
}
