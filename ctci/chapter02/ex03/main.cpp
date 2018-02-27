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

	node* runner = head;

	for(int i = 1; i < a.size(); i++) {
		node* n = new node(a[i]);
		runner->next = n;
		runner = runner->next;
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

void deleteNode(node* target) {
	node* temp = target->next;
	target->data = target->next->data;
	target->next = target->next->next;
	delete temp;
}

int main() {
	node* m;
	node* n;
	node* target;

	m = createList(vi({1, 2, 3}));
	target = m->next;
	deleteNode(target);
	n = createList(vi({1, 3}));
	assert(listsAreEqual(m, n));

	m = createList(vi({1, 2, 3, 4, 5}));
	target = m->next->next;
	deleteNode(target);
	n = createList(vi({1, 2, 4, 5}));
	assert(listsAreEqual(m, n));

	cout << "success" << endl;

	return 0;
}