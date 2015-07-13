class Queue {
private:
	stack<int> a;
public:
	void push(int x) {
		a.push(x);
		return;
	}

	void pop(void) {
		stack<int> b;
		while(!a.empty()){
			b.push(a.top());
			a.pop();
		}
		b.pop();
		while(!b.empty()) {
			a.push(b.top());
			b.pop();
		}
		return;
	}

	int peek(void) {
		stack<int> b;
		while(!a.empty()) {
			b.push(a.top());
			a.pop();
		}
		int ans = b.top();
		while(!b.empty()) {
			a.push(b.top());
			b.pop();
		}
		return ans;
	}

	bool empty(void) {
		return a.empty();
	}
}
