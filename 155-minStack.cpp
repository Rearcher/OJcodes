class MinStack {
private:
	vector<int> a;
	vector<int> m;
public:
	void push(int x) {
		a.push_back(x);
		if(a.size()==1) {
			m.push_back(x);
		}
		else {
			int len=m.size();
			m.push_back(min(x,m[len-1]));
		}
	}

	void pop() {
		a.pop_back();
		m.pop_back();
	}

	int top() {
		int len=a.size();
		return a[len-1];
	}

	int getMin() {
		int len=a.size();
		return m[len-1];
	}
};
