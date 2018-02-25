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
		node* d = new node(a[i]);

		prev->next = d;
		prev = d;
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

node* removeDuplicatesBuffer(node* head) {
	if(head == NULL) {
		return NULL;
	}

	unordered_set<int> s;

	s.insert(head->data);

	node* current = head;

	while(current->next) {
		if(s.find(current->next->data) != s.end()) {
			node* temp = current->next;
			current->next = current->next->next;
			delete temp;
		} else {
			s.insert(current->next->data);
			current = current->next;
		}
	}

	return head;
}

node* removeDuplicatesNoBuffer(node* head) {
	if(head == NULL) {
		return NULL;
	}

	node* current = head;

	while(current) {
		node * runner = current;

		while(runner->next) {
			if(runner->next->data == current->data) {
				node* temp = runner->next;
				runner->next = runner->next->next;
				delete temp;
			} else {
				runner = runner->next;
			}
		}

		current = current->next;
	}

	return head;
}

int main() {
	node* m;
	m = createList(vi({1, 2, 2, 3}));
	m = removeDuplicatesNoBuffer(m);
	assert(listsAreEqual(m, createList(vi({1, 2, 3}))));

	m = createList(vi({1, 1, 2, 2, 3}));
	m = removeDuplicatesNoBuffer(m);
	assert(listsAreEqual(m, createList(vi({1, 2, 3}))));

	m = createList(vi({1, 1, 2, 2, 3, 3}));
	m = removeDuplicatesNoBuffer(m);
	assert(listsAreEqual(m, createList(vi({1, 2, 3}))));

	m = createList(vi({1, 1, 1, 1}));
	m = removeDuplicatesNoBuffer(m);
	assert(listsAreEqual(m, createList(vi({1}))));

	m = NULL;
	m = removeDuplicatesNoBuffer(m);
	assert(listsAreEqual(m, createList(vi())));

	cout << "success" << endl;

	return 0;
}