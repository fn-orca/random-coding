#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

struct node {
	int data;
	node* next;
	node(int _data) : data(_data), next(NULL) {}
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
		prev = prev->next;
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

node* partition(node* head, int k) {
	if(head == NULL) {
		return NULL;
	}

	node* aStart = NULL;
	node* bStart = NULL;
	node* aRunner = NULL;
	node* bRunner = NULL;

	node* current = head;

	while(current) {
		if(current->data < k) {
			if(aStart == NULL) {
				aStart = current;
				aRunner = current;
			} else {
				aRunner->next = current;
				aRunner = aRunner->next;
			}
		}

		if(current->data >= k) {
			if(bStart == NULL) {
				bStart = current;
				bRunner = current;
			} else {
				bRunner->next = current;
				bRunner = bRunner->next;
			}
		}

		current = current->next;
	}

	if(aStart == NULL) {
		return bStart;
	}
	
	if(bRunner) {
		bRunner->next = NULL;
	}

	aRunner->next = bStart;
	return aStart;
}

int main() {
	node* m;
	node* n;

	m = createList(vi({4, 3, 2, 1}));
	m = partition(m, 3);
	n = createList(vi({2, 1, 4, 3}));
	assert(listsAreEqual(m, n));

	m = createList(vi({1, 1, 1, 1}));
	m = partition(m, 3);
	n = createList(vi({1, 1, 1, 1}));
	assert(listsAreEqual(m, n));

	m = createList(vi({2, 2, 2}));
	m = partition(m, 1);
	n = createList(vi({2, 2, 2}));
	assert(listsAreEqual(m, n));

	m = createList(vi({1}));
	m = partition(m, 3);
	n = createList(vi({1}));
	assert(listsAreEqual(m, n));

	m = createList(vi({}));
	m = partition(m, 3);
	n = createList(vi({}));
	assert(listsAreEqual(m, n));

	m = createList(vi({1, 3, 2, 4}));
	m = partition(m, 3);
	n = createList(vi({1, 2, 3, 4}));
	assert(listsAreEqual(m, n));

	m = createList(vi({4, 2, 3, 1}));
	m = partition(m, 3);
	n = createList(vi({2, 1, 4, 3}));
	assert(listsAreEqual(m, n));

	cout << "success" << endl;

	return 0;
}