class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> s;
		for(int i=0; i<tokens.size(); i++) {
			string str = tokens[i];
			if(str!="+" && str!="-" && str!="*" && str!="/")
				s.push(atoi(str.c_str()));
			else {
				int a = s.top();
				s.pop();
				int b = s.top();
				s.pop();
				if(str == "+") s.push(a+b);
				if(str == "-") s.push(b-a);
				if(str == "*") s.push(a*b);
				if(str == "/") s.push(b/a);
			}
		}
		return s.top();
	}
};
