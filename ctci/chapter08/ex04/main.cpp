#include<bits/stdc++.h>

using namespace std;

vector<int> aux;

void printAux() {
	cout << "{";

	for(int i = 0; i < aux.size(); i++) {
		if(i) {
			cout << ", ";
		}
		cout << aux[i];
	}

	cout << "}";

	cout << endl;
}

void printAllSubsets(vector<int> &v, int current) {
	if(current >= v.size()) {
		printAux();
		return;
	}
	printAllSubsets(v, current + 1);
	aux.push_back(v[current]);
	printAllSubsets(v, current + 1);
	aux.pop_back();
}

void printAllSubsets(vector<int> v) {
	printAllSubsets(v, 0);
}

void test0() {
	vector<int> a({1, 2, 3, 4});

	cout << "test0 subsets:" << endl;
	printAllSubsets(a);
}

int main() {
	test0();

	cout << "success" << endl;

	return 0;
}