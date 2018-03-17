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

map<int, int> m;

int countPathsWithSumAux(node* current, int currentSum, int targetSum) {
	if(current == NULL) {
		return 0;
	}

	currentSum += current->data;

	int ans = 0;

	if(currentSum == targetSum) {
		ans++;
	}

	int toFind = currentSum - targetSum;

	ans += m[toFind];

	m[currentSum]++;

	ans += countPathsWithSumAux(current->left, currentSum, targetSum);
	ans += countPathsWithSumAux(current->right, currentSum, targetSum);

	m[currentSum]--;

	return ans;
}

int countPathsWithSum(node* root, int targetSum) {
	return countPathsWithSumAux(root, 0, targetSum);
}

void test0() {
	node* a = NULL;

	int ans = countPathsWithSum(a, 1);

	assert(ans == 0);
}

void test1() {
	node* a = new node(1);

	assert(countPathsWithSum(a, 1) == 1);
	assert(countPathsWithSum(a, 0) == 0);
}

void test2() {
	node* a = new node(2);
	a->left = new node(1);
	a->right = new node(1);

	assert(countPathsWithSum(a, 2) == 1);
	assert(countPathsWithSum(a, 3) == 2);
	assert(countPathsWithSum(a, 1) == 2);
}

void test3() {
	node* a = new node(1);
	a->left = new node(1);
	a->right = new node(1);
	a->left->left = new node(1);

	assert(countPathsWithSum(a, 2) == 3);
	assert(countPathsWithSum(a, 1) == 4);
	assert(countPathsWithSum(a, 3) == 1);
}

int main() {
	test0();
	test1();
	test2();

	cout << "success" << endl;

	return 0;
}