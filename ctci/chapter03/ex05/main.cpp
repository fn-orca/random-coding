#include<bits/stdc++.h>

using namespace std;

struct sortedStack {
	stack<int> s;

	void push(int n) {
		stack<int> aux;

		while(s.size() > 0 && n > s.top()) {
			aux.push(s.top());
			s.pop();
		}

		s.push(n);

		while(aux.size() > 0) {
			s.push(aux.top());
			aux.pop();
		}
	}

	int top() {
		return s.top();
	}

	void pop() {
		s.pop();
	}
};

int main() {
	sortedStack s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.pop();
	s.push(4);

	assert(s.top() == 2);

	s.pop();

	assert(s.top() == 3);

	s.pop();

	assert(s.top() == 4);

	cout << "success" << endl;

	return 0;
}