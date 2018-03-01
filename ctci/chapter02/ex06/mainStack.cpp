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

int getListSize(node* head) {
	if(head == NULL) {
		return 0;
	}

	int count = 0;

	while(head) {
		count++;
		head = head->next;
	}

	return count;
}

bool isPalindrome(node* head) {
	if(head == NULL) {
		return true;
	}

	node* slow = head;
	node* fast = head;

	stack<int> s;

	while(fast && fast->next) {
		s.push(slow->data);

		slow = slow->next;
		fast = fast->next->next;
	}

	if(fast) {
		slow = slow->next;
	}

	while(slow) {
		if(slow->data != s.top()) {
			return false;
		}

		slow = slow->next;
		s.pop();
	}

	return true;
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