#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

struct node {
	int data;
	node* left;
	node* right;

	node(int _data) {
		data = _data;
		left = right = NULL;
	}
};

vvi weaves;

void weaveAux(vi &a, vi &b, int ia, int ib, vi &current) {
	if(current.size() == a.size() + b.size()) {
		weaves.push_back(current);
		return;
	}

	if(ia < a.size()) {
		current.push_back(a[ia]);
		weaveAux(a, b, ia + 1, ib, current);
		current.pop_back();
	}
	if(ib < b.size()) {
		current.push_back(b[ib]);
		weaveAux(a, b, ia, ib + 1, current);
		current.pop_back();
	}
}

vvi weave(vvi a, vvi b) {
	weaves.clear();
	vi current;

	for(int i = 0; i < a.size(); i++) {
		for(int j = 0; j < b.size(); j++) {
			weaveAux(a[i], b[j], 0, 0, current);
		}
	}

	if(weaves.size() == 0) {
		weaves.push_back(vi());
	}

	return weaves;
}

vvi getSequences(node* root) {
	if(root == NULL) {
		return vvi();
	}

	vvi seqsLeft = getSequences(root->left);
	vvi seqsRight = getSequences(root->right);

	vvi weaves = weave(seqsLeft, seqsRight);

	for(int i = 0; i < weaves.size(); i++) {
		vi temp(1);
		temp[0] = root->data;

		vi curr = weaves[i];

		temp.insert(temp.end(), curr.begin(), curr.end());

		weaves[i] = temp;
	}

	return weaves;
}

void printSequences(vvi seqs) {
	for(int i = 0; i < seqs.size(); i++) {
		vi current = seqs[i];
		for(int i = 0; i < current.size(); i++) {
			if(i) {
				cout << " ";
			}
			cout << current[i];
		}
		cout << endl;
	}
}

void test0() {
	node* a = new node(2);
	a->left = new node(1);
	a->right = new node(3);

	printSequences(getSequences(a));
	cout << endl;
}

void test1() {
	node* a = new node(4);
	a->left = new node(2);
	a->right = new node(6);
	a->left->left = new node(1);
	a->left->right = new node(3);
	a->right->left = new node(5);
	a->right->right = new node(7);

	printSequences(getSequences(a));
	cout << endl;
}

int main() {
	test0();
	test1();

	cout << "success" << endl;

	return 0;
}