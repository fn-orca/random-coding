#include<bits/stdc++.h>

using namespace std;

struct node {
	int data;
	node* left;
	node* right;

	node(int _data) {
		data = _data;
		left = NULL;
		right = NULL;
	}
};

void getPreorderStringAux(node* root, string &s) {
	if(root == NULL) {
		s += "X$";
		return;
	}

	s += root->data + "$";

	getPreorderStringAux(root->left, s);
	getPreorderStringAux(root->right, s);
}

string getPreorderString(node* root) {
	string s = "";

	getPreorderStringAux(root, s);

	return s;
}

// check if b is subtree of a
bool isSubtree(node* a, node* b) {
	string strA = getPreorderString(a);
	string strB = getPreorderString(b);

	return strA.find(strB) != string::npos;
}

void test0() {
	node* a = new node(4);
	a->left = new node(2);
	a->right = new node(6);
	a->left->left = new node(1);
	a->left->right = new node(3);
	a->right->left = new node(5);
	a->right->right = new node(7);

	node* b = new node(2);
	b->left = new node(1);
	b->right = new node(3);

	assert(isSubtree(a, b));
}

int main() {
	test0();

	cout << "success" << endl;

	return 0;
}