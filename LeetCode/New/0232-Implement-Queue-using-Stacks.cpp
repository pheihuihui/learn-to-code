class MyQueue {
public:
	MyQueue() {
		st = stack<int>();
	}

	void push(int x) {
		st.push(x);
	}

	int pop() {
		vector<int> tmp;
		while (!st.empty()) {
			tmp.push_back(st.top());
			st.pop();
		}
		for (auto a = tmp.rbegin() + 1; a != tmp.rend(); a++)
			st.push(*a);
		return *tmp.rbegin();
	}

	int peek() {
		vector<int> tmp;
		while (!st.empty()) {
			tmp.push_back(st.top());
			st.pop();
		}
		for (auto a = tmp.rbegin(); a != tmp.rend(); a++)
			st.push(*a);
		return *tmp.rbegin();
	}

	bool empty() {
		return st.empty();
	}
private:
	stack<int> st;
};