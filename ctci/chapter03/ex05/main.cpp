#include<bits/stdc++.h>

const int INF = 1 << 30;

using namespace std;

void sort(stack<int> &s) {
	stack<int> aux;
	int originalSize = s.size();

	for(int i = 0; i < originalSize - 1; i++) {
		int maxi = -INF;

		for(int j = 0; j < originalSize - i; j++) {
			maxi = max(maxi, s.top());
			aux.push(s.top());
			s.pop();
		}

		s.push(maxi);

		bool pushedMaxi = false;

		while(aux.size()) {
			if(aux.top() == maxi && !pushedMaxi) {
				pushedMaxi = true;
			} else {
				s.push(aux.top());
			}
			aux.pop();
		}
	}
}

int main() {
	stack<int> s;
	s.push(3);
	s.push(1);
	s.push(3);
	s.push(4);
	s.push(2);

	sort(s);

	assert(s.top() == 1);

	s.pop();
	assert(s.top() == 2);

	s.pop();
	assert(s.top() == 3);

	s.pop();
	assert(s.top() == 3);

	s.pop();
	assert(s.top() == 4);

	cout << "success" << endl;

	return 0;
}