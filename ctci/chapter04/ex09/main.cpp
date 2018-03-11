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

set<string> sequences;
vi currentSequence;
int treeSize;

int getTreeSize(node *root) {
	if(root == NULL) {
		return 0;
	}
	return 1 + getTreeSize(root->left) + getTreeSize(root->right);
}

void getSequencesAux(node* root) {
	if(root == NULL) {
		return;
	}

	currentSequence.push_back(root->data);

	if(currentSequence.size() == treeSize) {
		sequences.push_back(currentSequence);
	} else {
		getSequencesAux(root->left);
		getSequencesAux(root->right);

		getSequencesAux(root->right);
		getSequencesAux(root->left);
	}

	currentSequence.pop_back();
}

set<vi> getSequences(node* root) {
	sequences.clear();
	currentSequence.clear();
	treeSize = getTreeSize(root);

	getSequencesAux(root);

	return sequences;
}

void printSequences(set<vi> seqs) {
	for(auto it = seqs.begin(); it != seqs.end(); it++) {
		vi current = (*it);
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
}

int main() {
	test0();

	cout << "success" << endl;

	return 0;
}