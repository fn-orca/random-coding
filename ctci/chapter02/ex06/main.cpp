#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

using namespace std;

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
	node* current = head->next;

	prev->next = NULL;

	while(current) {
		node* temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
	}

	return prev;
}

node* copyList(node* head) {
	if(head == NULL) {
		return NULL;
	}

	node* copy = new node(head->data);
	node* prev = copy;
	node* current = head->next;

	while(current) {
		node* n = new node(current->data);
		prev->next = n;
		prev = n;
		current = current->next;
	}

	return copy;
}

bool isPalindrome(node* head) {
	if(head == NULL) {
		return true;
	}

	node* copy = copyList(head);
	node* reversedCopy = reverseList(copy);

	return listsAreEqual(head, reversedCopy);
}

int main() {
	node* m;

	m = createList(vi({1, 2, 3, 4}));
	assert(isPalindrome(m) == false);

	m = createList(vi({1}));
	assert(isPalindrome(m) == true);

	m = createList(vi({2, 1, 2}));
	assert(isPalindrome(m) == true);

	m = createList(vi({2, 2, 2, 2}));
	assert(isPalindrome(m) == true);

	m = createList(vi({0, 0, 1}));
	assert(isPalindrome(m) == false);

	cout << "success" << endl;

	return 0;
}