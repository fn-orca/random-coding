#include<bits/stdc++.h>

using namespace std;

struct bigStack {
	vector<stack<int>> stacks;
	int limit;

	bigStack() {
		limit = 2;
		stacks = vector<stack<int>>(1);
	}

	void push(int n) {
		int currentStack = stacks.size() - 1;

		if(stacks[currentStack].size() == limit) {
			stacks.push_back(stack<int>());
			currentStack++;
		}

		stacks[currentStack].push(n);
	}

	void pop() {
		int currentStack = stacks.size() - 1;

		stacks[currentStack].pop();
		if(stacks[currentStack].size() == 0 && currentStack > 0) {
			stacks.pop_back();
		}
	}

	int top() {
		int currentStack = stacks.size() - 1;

		return stacks[currentStack].top();
	}

	void popAt(int index) {
		stack<int> aux;

		while(stacks.size() - 1 > index) {
			aux.push(top());
			pop();
		}

		pop();

		while(aux.size() > 0) {
			push(aux.top());
			aux.pop();
		}
	}
};

int main() {
	bigStack s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	s.popAt(1);

	assert(s.top() == 5);

	s.pop();

	assert(s.top() == 3);

	s.popAt(0);

	assert(s.top() == 3);

	s.pop();

	assert(s.top() == 1);

	cout << "success" << endl;

	return 0;
}