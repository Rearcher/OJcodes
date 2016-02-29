class Solution {
private:
	queue<int> a;
public:
	void push(int x) {
		a.push(x);
		return;
	}

	void pop() {
		queue<int> b;
		while(a.size()>1) {
			b.push(a.front());
			a.pop();
		}
		a.pop();
		while(!b.empty()) {
			a.push(b.front());
			b.pop();
		}
		return;
	}

	int top() {
		return a.back();
	}

	bool empty() {
		return a.empty();
	}
}
