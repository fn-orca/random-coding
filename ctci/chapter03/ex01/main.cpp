#include<bits/stdc++.h>

using namespace std;

struct arrayStack {
	vector<int> v;
	int a;
	int b;
	int c;

	int aSize;
	int bSize;
	int cSize;

	arrayStack(int n) {
		v = vector<int>(n);

		a = 0;
		b = 1;
		c = 2;

		aSize = 0;
		bSize = 0;
		cSize = 0;
	}

	void push(int stackNum, int value) {
		if(stackNum == 1) {
			if(aSize == v.size() / 3) {
				return;
			}
			v[a] = value;
			a += 3;
			aSize++;
		}
		if(stackNum == 2) {
			if(bSize == v.size() / 3) {
				return;
			}
			v[b] = value;
			b += 3;
			bSize++;
		}
		if(stackNum == 3) {
			if(cSize == v.size() / 3) {
				return;
			}
			v[c] = value;
			c += 3;
			cSize++;
		}
	}

	void pop(int stackNum) {
		if(stackNum == 1) {
			if(aSize == 0) {
				return;
			}
			a -= 3;
			aSize--;
		}
		if(stackNum == 2) {
			if(bSize == 0) {
				return;
			}
			b -= 3;
			bSize--;
		}
		if(stackNum == 3) {
			if(cSize == 0) {
				return;
			}
			c -= 3;
			cSize--;
		}
	}

	int top(int stackNum) {
		if(stackNum == 1) {
			if(aSize == 0) {
				return -1;
			}
			return v[a-3];
		}
		if(stackNum == 2) {
			if(bSize == 0) {
				return -1;
			}
			return v[b-3];
		}
		if(stackNum == 3) {
			if(cSize == 0) {
				return -1;
			}
			return v[c-3];
		}
	}
};



int main() {
	arrayStack* s;

	s = new arrayStack(3);
	s->push(1, 1);
	s->push(1, 2);
	assert(s->top(1) == 1);

	cout << "success" << endl;

	return 0;
}