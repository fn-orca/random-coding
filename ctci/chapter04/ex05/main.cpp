#include<bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

struct node {
	int data;
	node* left;
	node* right;

	node(int _data) {
		data = _data;
		left = right = NULL;
	}
};

bool isBstAux(node* root, int mini, int maxi) {
	if(root == NULL) {
		return true;
	}

	bool thisOk = root->data > mini && root->data <= maxi;
	bool leftOk = isBstAux(root->left, mini, root->data);
	bool rightOk = isBstAux(root->right, root->data, maxi);

	return thisOk && leftOk && rightOk;
}

bool isBst(node* root) {
	return isBstAux(root, -INF, INF);
}

bool test0() {
	node* a = NULL;

	return isBst(a) == true;
}

bool test1() {
	node* a = new node(1);

	return isBst(a) == true;
}

bool test2() {
	node* a = new node(2);
	a->left = new node(1);
	a->right = new node(3);

	return isBst(a) == true;
}

bool test3() {
	node* a = new node(4);
	a->left = new node(2);
	a->right = new node(6);
	a->left->left = new node(1);
	a->left->right = new node(5);
	a->right->left = new node(3);
	a->right->right = new node(7);

	return isBst(a) == false;
}

bool test4() {
	node* a = new node(4);
	a->left = new node(2);
	a->right = new node(6);
	a->left->left = new node(1);
	a->left->right = new node(3);
	a->right->left = new node(5);
	a->right->right = new node(7);

	return isBst(a) == true;
}

bool test5() {
	node* a = new node(10);
	a->left = new node(4);
	a->left->left = new node(5);
	a->left->right = new node(6);

	return isBst(a) == false;
}

bool test6() {
	node* a = new node(4);
	a->left = new node(4);
	a->right = new node(5);

	return isBst(a) == true;
}

int main() {
	assert(test0());
	assert(test1());
	assert(test2());
	assert(test3());
	assert(test4());
	assert(test5());
	assert(test6());

	cout << "success" << endl;

	return 0;
}