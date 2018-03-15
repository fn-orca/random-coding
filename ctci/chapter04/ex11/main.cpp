#include<bits/stdc++.h>

using namespace std;

class node {
private:
	int data;
	node* left;
	node* right;
	int size;

public:
	node(int _data) {
		data = _data;
		left = NULL;
		right = NULL;
		size = 1;
	}

	void insert(int data) {
		if(data <= this->data) {
			if(left) {
				left->insert(data);
			} else {
				left = new node(data);
			}
		} else {
			if(right) {
				right->insert(data);
			} else {
				right = new node(data);
			}
		}

		this->size++;
	}

	int getSize() {
		return size;
	}

	node* getRandomNode(int index) {
		int leftSize = left ? left->getSize() : 0;

		if(leftSize < index) {
			return left->getRandomNode(index);
		} else if(leftSize == index) {
			return this;
		} else {
			return right->getRandomNode(index - leftSize - 1);
		}
	}
};

class tree {
private:
	node* root;
public:
	tree() {
		root = NULL;
	}

	void insert(int data) {
		if(root == NULL) {
			root = new node(data);
		} else {
			root->insert(data);
		}
	}

	node* getRandomNode() {
		if(root) {
			int index = rand() % root->getSize();
			return root->getRandomNode(index);
		}
	}
};

int main() {
	srand(time(NULL));

	cout << "success" << endl;

	return 0;
}