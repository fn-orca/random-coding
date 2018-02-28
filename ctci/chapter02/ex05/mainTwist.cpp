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

node* reverseList(node* head) {
	if(head == NULL) {
		return NULL;
	}

	node* prev = head;
	node* runner = head->next;
	prev->next = NULL;

	while(runner) {
		node* temp = runner->next;
		runner->next = prev;
		prev = runner;
		runner = temp;
	}

	return prev;
}

node* sumLists(node* a, node* b) {
	if(a == NULL) {
		return b;
	}
	if(b == NULL) {
		return a;
	}

	a = reverseList(a);
	b = reverseList(b);

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

	return reverseList(sum);
}

int main() {
	node* m;
	node* n;
	node* s;
	node* test;

	m = createList(vi({1, 0}));
	n = createList(vi({2, 0}));
	s = sumLists(m, n);
	test = createList(vi({3, 0}));
	assert(listsAreEqual(s, test));

	m = createList(vi({1, 0}));
	n = createList(vi());
	s = sumLists(m, n);
	test = createList(vi({1, 0}));
	assert(listsAreEqual(s, test));

	m = createList(vi());
	n = createList(vi({1, 0}));
	s = sumLists(m, n);
	test = createList(vi({1, 0}));
	assert(listsAreEqual(s, test));

	m = createList(vi({9}));
	n = createList(vi({9}));
	s = sumLists(m, n);
	test = createList(vi({1, 8}));
	assert(listsAreEqual(s, test));

	m = createList(vi({1, 1}));
	n = createList(vi({9}));
	s = sumLists(m, n);
	test = createList(vi({2, 0}));
	assert(listsAreEqual(s, test));

	m = createList(vi({9, 9}));
	n = createList(vi({9, 9}));
	s = sumLists(m, n);
	test = createList(vi({1, 9, 8}));
	assert(listsAreEqual(s, test));

	m = createList(vi({6, 1, 7}));
	n = createList(vi({2, 9, 5}));
	s = sumLists(m, n);
	test = createList(vi({9, 1, 2}));
	assert(listsAreEqual(s, test));

	cout << "success" << endl;

	return 0;
}