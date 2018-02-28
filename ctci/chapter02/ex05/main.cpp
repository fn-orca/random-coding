#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

struct node {
	int data;
	node* next;
	node(int _data) : data(_data), next(NULL) {	}
};

node* createList(vi a) {
	if(a.size() == 0) {
		return NULL;
	}
	node* head = new node(a[0]);

	node* prev = head;

	for(int i = 1; i < a.size(); i++) {
		node* n = new node(a[i]);
		prev->next = n;
		prev = n;
	}

	return head;
}

bool listsAreEqual(node* l1, node* l2) {
	while(l1 && l2) {
		if(l1->data != l2->data) {
			return false;
		}
		l1 = l1->next;
		l2 = l2->next;
	}
	return l1 == l2;
}

node* sumLists(node* a, node* b) {
	if(a == NULL) {
		return b;
	}
	if(b == NULL) {
		return a;
	}

	int d = a->data + b->data;
	node* sum = new node(d % 10);
	int carry = a->data + b->data;
	carry /= 10;

	node* prev = sum;

	a = a->next;
	b = b->next;

	while(a || b || carry) {
		d = carry;
		if(a) {
			d += a->data;
		}
		if(b) {
			d += b->data;
		}

		node* n = new node(d % 10);
		carry = d / 10;

		prev->next = n;
		prev = n;

		if(a) {
			a = a->next;
		}
		if(b) {
			b = b->next;
		}
	}

	return sum;
}

int main() {
	node* m;
	node* n;
	node* s;
	node* test;

	m = createList(vi({0, 1}));
	n = createList(vi({0, 2}));
	s = sumLists(m, n);
	test = createList(vi({0, 3}));
	assert(listsAreEqual(s, test));

	m = createList(vi({0, 1}));
	n = createList(vi());
	s = sumLists(m, n);
	test = createList(vi({0, 1}));
	assert(listsAreEqual(s, test));

	m = createList(vi());
	n = createList(vi({0, 1}));
	s = sumLists(m, n);
	test = createList(vi({0, 1}));
	assert(listsAreEqual(s, test));

	m = createList(vi({9}));
	n = createList(vi({9}));
	s = sumLists(m, n);
	test = createList(vi({8, 1}));
	assert(listsAreEqual(s, test));

	m = createList(vi({1, 1}));
	n = createList(vi({9}));
	s = sumLists(m, n);
	test = createList(vi({0, 2}));
	assert(listsAreEqual(s, test));

	m = createList(vi({9, 9}));
	n = createList(vi({9, 9}));
	s = sumLists(m, n);
	test = createList(vi({8, 9, 1}));
	assert(listsAreEqual(s, test));

	cout << "success" << endl;

	return 0;
}