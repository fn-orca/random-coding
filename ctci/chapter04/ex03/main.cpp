#include<bits/stdc++.h>

using namespace std;

struct node {
	int data;
	node* next;
	node* left;
	node* right;

	node(int _data) {
		data = _data;
		left = right = next = NULL;
	}
};

void go(vector<node*> &list, node* root, int level) {
	if(root == NULL) {
		return;
	}

	int aux = list.size() - 1;

	if(aux >= level) {
		root->next = list[level];
		list[level] = root;
	} else {
		list.push_back(root);
	}

	go(list, root->left, level + 1);
	go(list, root->right, level + 1);
}

vector<node*> getListOfDepths(node* root) {
	vector<node*> list;

	go(list, root, 0);

	return list;
}

bool listsAreEqual(node* a, node* b) {
	while(a && b) {
		if(a->data != b->data) {
			return false;
		}

		a = a->next;
		b = b->next;
	}

	return a == b;
}

bool test0() {
	node* a = NULL;
	vector<node*> real = getListOfDepths(a);

	return real.size() == 0;
}

bool test1() {
	node* a = new node(1);
	vector<node*> real = getListOfDepths(a);

	bool sizeOk = real.size() == 1;
	bool contentOk = real[0]->data == 1;

	return sizeOk && contentOk;
}

bool test2() {
	node* a = new node(4);
	a->left = new node(2);
	a->right = new node(6);
	a->left->left = new node(1);
	a->left->right = new node(3);
	a->right->left = new node(5);
	a->right->right = new node(7);

	vector<node*> real = getListOfDepths(a);

	vector<node*> ctrl(3);
	ctrl[0] = new node(4);

	ctrl[1] = new node(6);
	ctrl[1]->next = new node(2);

	ctrl[2] = new node(7);
	ctrl[2]->next = new node(5);
	ctrl[2]->next->next = new node(3);
	ctrl[2]->next->next->next = new node(1);

	bool sizeOk = real.size() == ctrl.size();
	bool contentOk = true;

	for(int i = 0; i < real.size(); i++) {
		if(!listsAreEqual(real[i], ctrl[i])) {
			contentOk = false;
			break;
		}
	}

	return sizeOk && contentOk;
}

int main() {
	assert(test0());
	assert(test1());
	assert(test2());

	cout << "success" << endl;

	return 0;
}