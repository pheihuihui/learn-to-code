class MyStack {
public:
	MyStack() {
		que = priority_queue<int>();
	}

	void push(int x) {
		que.push(x);
	}

	int pop() {
		int tmp = que.top();
		que.pop();
		return tmp;
	}

	int top() {
		return que.top();
	}

	bool empty() {
		return que.empty();
	}
private:
	priority_queue<int> que;
};