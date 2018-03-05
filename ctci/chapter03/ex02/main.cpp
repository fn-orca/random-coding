#include<bits/stdc++.h>

using namespace std;

struct minStack {
	stack<int> regular;
	stack<int> mins;

	void push(int n) {
		if(mins.size() == 0) {
			mins.push(n);
		} else {
			if(n <= mins.top()) {
				mins.push(n);
			}
		}
		regular.push(n);
	}

	int min() {
		return mins.top();
	}

	int top() {
		return regular.top();
	}

	void pop() {
		int n = regular.top();

		if(mins.top() == n) {
			mins.pop();
		}

		regular.pop();
	}
};

int main() {
	minStack s;

	s.push(10);
	assert(s.min() == 10);
	s.push(9);
	assert(s.min() == 9);
	s.push(9);
	assert(s.min() == 9);
	s.push(10);
	assert(s.min() == 9);
	assert(s.top() == 10);
	s.push(8);
	s.push(10);
	assert(s.min() == 8);
	s.pop();
	s.pop();
	assert(s.min() == 9);
	s.pop();
	s.pop();
	s.pop();
	assert(s.min() == 10);
	assert(s.top() == 10);

	cout << "success" << endl;

	return 0;
}