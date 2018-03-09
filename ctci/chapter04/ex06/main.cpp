#include<bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

struct node {
	int data;
	node* left;
	node* right;
	node* parent;

	node(int _data) {
		data = _data;
		left = right = parent = NULL;
	}

	node(int _data, node* _parent) {
		data = _data;
		left = right = NULL;
		parent = _parent;
	}
};

node* getMin(node* current) {
	if(current == NULL) {
		return NULL;
	}

	node* mini = getMin(current->left);

	return mini ? mini : current;
}

node* getSuccessor(node* current) {
	if(current == NULL) {
		return NULL;
	}

	// has right sub-tree
	if(current->right) {
		return getMin(current->right);
	}

	// current is root
	if(current->parent == NULL) {
		return NULL;
	}

	// current is left child
	if(current->parent->left == current) {
		return current->parent;
	}

	// current is right child
	node* successor = current->parent;

	while(successor && successor->data <= current->data) {
		successor = successor->parent;
	}

	return successor;
}

bool test0() {
	node* a = NULL;

	return getSuccessor(a) == NULL;
}

bool test1() {
	node* a = new node(1);

	return getSuccessor(a) == NULL;
}

bool test2() {
	node* a = new node(1);
	a->right = new node(2, a);

	return getSuccessor(a)->data = 2;
}

bool test3() {
	node* a = new node(1);
	a->right = new node(3, a);
	a->right->left = new node(2, a->right);

	return getSuccessor(a)->data == 2;
}

bool test4() {
	node* a = new node(10);
	a->left = new node(1, a);

	return getSuccessor(a->left)->data == 10;
}

bool test5() {
	node* a = new node(10);
	a->left = new node(1, a);

	return getSuccessor(a) == NULL;
}

bool test6() {
	node* a = new node(10);
	a->left = new node(5, a);
	a->left->right = new node(7, a->left);

	return getSuccessor(a->left->right)->data == 10;
}

bool test7() {
	node* a = new node(10);
	a->left = new node(5, a);
	a->left->left = new node(3, a->left);

	return getSuccessor(a->left->left)->data == 5;
}

bool test8() {
	node* a = new node(100);
	a->left = new node(10, a);
	a->left->right = new node(20, a->left);
	a->left->right->right = new node(30, a->left->right);
	a->left->right->right->right = new node(40, a->left->right->right);

	return getSuccessor(a->left->right->right->right)->data == 100;
}

int main() {
	assert(test0());
	assert(test1());
	assert(test2());
	assert(test3());
	assert(test4());
	assert(test5());
	assert(test6());
	assert(test7());
	assert(test8());

	cout << "success" << endl;

	return 0;
}