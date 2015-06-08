//use stack
class Solution {
public:
	bool isValid(string s) {
		if(s.empty()) return true;
		stack<char> t;
		for(int i = 0; i < s.size(); i++) {
			if(s[i]=='(' || s[i]=='{' || s[i]=='[') {
				t.push(s[i]);
				continue;
			}
			if(s[i]==')' || s[i]=='}' || s[i]==']') {
				if(t.empty()) return false;
				char temp = t.top();
				t.pop();
				if((s[i]==')'&&temp!='(') || (s[i]=='}'&&temp!='{') || (s[i]==']'&&temp!='[')) return false;
			}
		}
		if(!t.empty()) return false; 
		return true;
	}
}
