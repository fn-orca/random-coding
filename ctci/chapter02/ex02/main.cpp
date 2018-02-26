#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

struct node {
	int data;
	node* next;

	node(int _data) : data(_data), next(NULL) { }
};

node* createList(vi a) {
	if(a.size() == 0) {
		return NULL;
	}

	node* head = new node(a[0]);
	node* prev = head;

	for(int i = 1; i < a.size(); i++) {
		node* current = new node(a[i]);
		prev->next = current;
		prev = current;
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

node* kthToLast(node* head, int k) {
	node* runner = head;

	for(int i = 0; i < k - 1; i++) {
		runner = runner->next;
	}

	while(runner->next != NULL) {
		runner = runner->next;
		head = head->next;
	}

	return head;
}

int main() {
	node* m;
	m = createList(vi({1, 2, 3, 4}));
	m = kthToLast(m, 1);
	assert(m->data == 4);

	m = createList(vi({1, 2, 3, 4}));
	m = kthToLast(m, 3);
	assert(m->data == 2);

	m = createList(vi({1}));
	m = kthToLast(m, 1);
	assert(m->data == 1);

	m = createList(vi({1, 2}));
	m = kthToLast(m, 1);
	assert(m->data == 2);

	m = createList(vi({1, 2}));
	m = kthToLast(m, 2);
	assert(m->data == 1);

	cout << "success" << endl;

	return 0;
}