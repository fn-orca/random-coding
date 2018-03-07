#include<bits/stdc++.h>

using namespace std;

struct myQueue {
	stack<int> oldFirst;
	stack<int> newFirst;

public:
	void push(int n) {
		newFirst.push(n);
	}

	int front() {
		if(oldFirst.size() > 0) {
			return oldFirst.top();
		} else if (newFirst.size() > 0) {
			swapStacks();
			return oldFirst.top();
		}
	}

	void pop() {
		if(oldFirst.size() > 0) {
			return oldFirst.pop();
		} else if (newFirst.size() > 0) {
			swapStacks();
			return oldFirst.pop();
		}
	}

private:
	void swapStacks() {
		while(newFirst.size() > 0) {
			oldFirst.push(newFirst.top());
			newFirst.pop();
		}
	}
};

int main() {
	myQueue q;

	q.push(1);
	q.push(2);
	q.push(3);

	assert(q.front() == 1);

	q.pop();

	assert(q.front() == 2);

	q.push(4);
	q.pop();

	assert(q.front() == 3);

	q.pop();

	assert(q.front() == 4);

	cout << "success" << endl;

	return 0;
}