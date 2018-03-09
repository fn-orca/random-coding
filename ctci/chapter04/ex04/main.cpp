#include<bits/stdc++.h>

using namespace std;

struct node {
	int data;
	node* left;
	node* right;

	node(int data) {
		this->data = data;
		left = right = NULL;
	}
};

struct result {
	int height;
	bool isBalanced;

	result(int height, bool isBalanced) {
		this->height = height;
		this->isBalanced = isBalanced;
	}
};

result isBalancedAux(node* root) {
	if(root == NULL) {
		return result(0, true);
	}

	result lResult = isBalancedAux(root->left);
	result rResult = isBalancedAux(root->right);

	int height = 1 + max(lResult.height, rResult.height);
	bool isBalanced = abs(lResult.height - rResult.height) <= 1;
	isBalanced = isBalanced && lResult.isBalanced;
	isBalanced = isBalanced && rResult.isBalanced;

	return result(height, isBalanced);
}

bool isBalanced(node* root) {
	return isBalancedAux(root).isBalanced;
}

bool test0() {
	node* a = NULL;

	return isBalanced(a) == true;
}

bool test1() {
	node* a = new node(1);

	return isBalanced(a) == true;
}

bool test2() {
	node* a = new node(1);
	a->left = new node(2);

	return isBalanced(a) == true;
}

bool test3() {
	node* a = new node(1);
	a->left = new node(2);
	a->left->left = new node(3);

	return isBalanced(a) == false;
}

bool test4() {
	node* a = new node(1);
	a->left = new node(2);
	a->left->left = new node(3);
	a->right = new node(4);

	return isBalanced(a) == true;
}

int main() {
	assert(test0());
	assert(test1());
	assert(test2());
	assert(test3());
	assert(test4());

	cout << "success" << endl;

	return 0;
}