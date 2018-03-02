#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

struct node {
	int data;
	node* next;
	node(int _data) : data(_data), next(NULL) {}
};

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

int getSizeOfList(node* head) {
	int count = 0;

	while(head) {
		count++;
		head = head->next;
	}

	return count;
}

node* intersection(node* a, node* b) {
	if(a == NULL || b == NULL) {
		return NULL;
	}

	int sizeA = getSizeOfList(a);
	int sizeB = getSizeOfList(b);

	node* small;
	node* large;

	if(sizeA <= sizeB) {
		small = a;
		large = b;
	} else {
		small = b;
		large = a;
	}

	for(int i = 0; i < abs(sizeA - sizeB); i++) {
		large = large->next;
	}

	while(small && large) {
		if(small == large) {
			return small;
		}
		small = small->next;
		large = large->next;
	}

	return NULL;
}

int main() {
	nn m;
	nn n;

	m = createList({1, 2, 3, 4, 5, 6});
	n = createList({1, 2, 3});
	n.second->next = m.first->next->next->next;
	assert(intersection(m.first, n.first)->data == 4);

	m = createList({1, 2, 3, 4, 5, 6});
	n = createList({1, 2, 3});
	n.second->next = m.first->next->next->next;
	assert(intersection(n.first, m.first)->data == 4);

	m = createList({1, 2, 3, 4, 5, 6});
	n = createList({-1, 0});
	n.second->next = m.first;
	assert(intersection(m.first, n.first)->data == 1);

	m = createList({1, 2, 3, 4, 5, 6});
	n = createList({-1, 0});
	n.second->next = m.first;
	assert(intersection(n.first, m.first)->data == 1);

	m = createList({1, 2, 3, 4, 5, 6});
	n = m;
	assert(intersection(n.first, m.first)->data == 1);

	m = createList({});
	n = m;
	assert(intersection(n.first, m.first) == NULL);

	m = createList({1, 2, 3, 4, 5, 6});
	n = createList({});
	assert(intersection(n.first, m.first) == NULL);

	m = createList({});
	n = createList({1, 2, 3, 4, 5, 6});
	assert(intersection(n.first, m.first) == NULL);

	m = createList({7, 8, 9});
	n = createList({1, 2, 3, 4, 5, 6});
	assert(intersection(n.first, m.first) == NULL);

	cout << "success" << endl;

	return 0;
}