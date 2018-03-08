#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

struct node {
	int data;
	node* left;
	node* right;

	node(int _data) {
		data = _data;
		left = right = NULL;
	}
};

node* getMinimalTree(vi &a, int l, int r) {
	if(l == r) {
		return NULL;
	}
	if(l == r - 1) {
		return new node(a[l]);
	}

	int middle = l + (r - l) / 2;

	node* root  = new node(a[middle]);
	node* left  = getMinimalTree(a, l, middle);
	node* right = getMinimalTree(a, middle + 1, r);

	root->left = left;
	root->right = right;

	return root;
}

node* getMinimalTree(vi &a) {
	return getMinimalTree(a, 0, a.size());
}

bool treesAreEqual(node* a, node* b) {
	if(a == NULL && b == NULL) {
		return true;
	}
	if(a == NULL || b == NULL) {
		return false;
	}
	if(a->data != b->data) {
		return false;
	}

	bool equalLefts = treesAreEqual(a->left, b->left);
	bool equalRights = treesAreEqual(a->right, b->right);

	return equalLefts && equalRights;
}

bool test0() {
	vi a;

	node* aReal = getMinimalTree(a);
	node* aTest = NULL;

	return treesAreEqual(aReal, aTest);
}

bool test1() {
	vi a = vi({1});

	node* aReal = getMinimalTree(a);
	node* aTest = new node(1);

	return treesAreEqual(aReal, aTest);
}

bool test2() {
	vi a = vi({1, 2});

	node* aReal = getMinimalTree(a);
	node* aTest = new node(2);
	aTest->left = new node(1);

	return treesAreEqual(aReal, aTest);
}

bool test3() {
	vi a = vi({1, 2, 3});

	node* aReal = getMinimalTree(a);
	node* aTest = new node(2);
	aTest->left = new node(1);
	aTest->right = new node(3);

	return treesAreEqual(aReal, aTest);
}

bool test4() {
	vi a = vi({1, 2, 3, 4});

	node* aReal = getMinimalTree(a);
	node* aTest = new node(3);
	aTest->left = new node(2);
	aTest->right = new node(4);
	aTest->left->left = new node(1);

	return treesAreEqual(aReal, aTest);
}

bool test5() {
	vi a = vi({1, 2, 3, 4, 5, 6 ,7});

	node* aReal = getMinimalTree(a);
	node* aTest = new node(4);
	aTest->left = new node(2);
	aTest->right = new node(6);
	aTest->left->left = new node(1);
	aTest->left->right = new node(3);
	aTest->right->left = new node(5);
	aTest->right->right = new node(7);

	return treesAreEqual(aReal, aTest);
}

int main() {
	assert(test0());
	assert(test1());
	assert(test2());
	assert(test3());
	assert(test4());
	assert(test5());

	cout << "success" << endl;

	return 0;
}