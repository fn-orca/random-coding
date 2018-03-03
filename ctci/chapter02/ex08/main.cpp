#include<bits/stdc++.h>

using namespace std;

struct node {
	int data;
	node* next;
	node(int _data) : data(_data), next(NULL) {}
};

typedef vector<int> vi;

typedef pair<node*, node*> nn;

nn createList(vi a) {
	if(a.size() == 0) {
		return nn(NULL, NULL);
	}

	node* head = new node(a[0]);

	node* prev = head;

	for(int i = 1; i < a.size(); i++) {
		node* n = new node(a[i]);
		prev->next = n;
		prev = n;
	}

	return nn(head, prev);
}

node* getLoopStart(node* head) {
	if(head == NULL) {
		return NULL;
	}

	node* slow = head;
	node* fast = head;

	while(true) {
		slow = slow->next;
		fast = fast->next->next;

		if(slow == fast) {
			while(slow != head) {
				slow = slow->next;
				head = head->next;
			}

			return head;
		}
	}

	return NULL;
}

int main() {
	nn m;

	m = createList(vi({1, 2, 3, 4, 5}));
	m.second->next = m.first->next->next;
	assert(getLoopStart(m.first)->data == 3);

	m = createList(vi({1, 2, 3, 4, 5}));
	m.second->next = m.first->next;
	assert(getLoopStart(m.first)->data == 2);

	m = createList(vi({1, 2}));
	m.second->next = m.first;
	assert(getLoopStart(m.first)->data == 1);

	m = createList(vi({1, 2, 3, 4, 5}));
	m.second->next = m.first;
	assert(getLoopStart(m.first)->data == 1);

	cout << "success" << endl;

	return 0;
}