#include<bits/stdc++.h>

using namespace std;

struct node {
	int data;
	node* left;
	node* right;

	node(int _data) {
		data = _data;
		left = right = NULL;
	}
};

struct result {
	bool hasA;
	bool hasB;
	node* lca;

	result(bool _hasA, bool _hasB, node* _lca) {
		hasA = _hasA;
		hasB = _hasB;
		lca = _lca;
	}
};

result getLcaAux(node* root, node* a, node* b) {
	if(root == NULL) {
		return result(false, false, NULL);
	}

	result lResult = getLcaAux(root->left, a, b);
	result rResult = getLcaAux(root->right, a, b);

	if(lResult.hasA && lResult.hasB)  {
		return lResult;
	}
	if(rResult.hasA && rResult.hasB) {
		return rResult;
	}

	bool bothSides = (lResult.hasA && rResult.hasB) || (rResult.hasA && lResult.hasB);
	bool isAAndHasB = root == a && (lResult.hasB || rResult.hasB);
	bool isBAndHasA = root == b && (lResult.hasA || rResult.hasA);

	if(bothSides || isAAndHasB || isBAndHasA) {
		return result(true, true, root);
	}

	bool hasA = root == a || lResult.hasA || rResult.hasA;
	bool hasB = root == b || lResult.hasB || rResult.hasB;

	return result(hasA, hasB, NULL);
}

node* getLca(node* root, node* a, node* b) {
	return getLcaAux(root, a, b).lca;
}

bool test0() {
	node* a = new node(1);
	a->right = new node(2);
	a->left = new node(0);

	bool okLeft = getLca(a, a, a->left)->data == 1;
	bool okRight = getLca(a, a, a->right)->data == 1;
	bool okMid = getLca(a, a->left, a->right)->data == 1;

	return okLeft && okRight && okMid;
}

bool test1() {
	node* a = new node(4);
	a->left = new node(2);
	a->left->left = new node(1);
	a->left->right = new node(3);

	return getLca(a, a->left->left, a->left->right)->data == 2;
}

bool test2() {
	node* a = new node(4);
	a->left = new node(2);
	a->left->left = new node(1);
	a->left->right = new node(3);
	a->left->left->left = new node(0);
	a->left->left->left->left = new node(-1);

	return getLca(a, a->left->left->left->left, a->left->right)->data == 2;
}

bool test3() {
	node* a = new node(4);
	a->left = new node(2);
	a->left->left = new node(1);
	a->left->right = new node(3);
	a->left->left->left = new node(0);
	a->left->left->left->left = new node(-1);

	a->right = new node(6);
	a->right->left = new node(5);

	return getLca(a, a->left->left->left->left, a->right->left)->data == 4;
}

bool test4() {
	node* a = new node(4);
	a->left = new node(2);
	a->left->left = new node(1);
	a->left->right = new node(3);

	node* b = new node(8);

	return getLca(a, a->left->left, b) == NULL;
}

int main() {
	assert(test0());
	assert(test1());
	assert(test2());
	assert(test3());

	cout << "success" << endl;

	return 0;
}