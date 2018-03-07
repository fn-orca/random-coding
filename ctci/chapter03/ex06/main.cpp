#include<bits/stdc++.h>

using namespace std;

const int DOG = 1;
const int CAT = 2;

struct node {
	int data;
	int type;
	int age;

	node(int d, int t) {
		data = d;
		type = t;
	}
};

struct animalQueue {
	int current = 0;
	queue<node*> dogs;
	queue<node*> cats;

	void push(node* animal) {
		animal->age = current++;

		if(animal->type == DOG) {
			dogs.push(animal);
		} else {
			cats.push(animal);
		}
	}

	node* dequeueAny() {
		if(dogs.size() == 0) {
			return dequeueCat();
		}
		if(cats.size() == 0) {
			return dequeueDog();
		}
		node* dog = dogs.front();
		node* cat = cats.front();
		if(dog->age < cat->age) {
			return dequeueDog();
		} else {
			return dequeueCat();
		}
	}

	node* dequeueDog() {
		if(dogs.size() == 0) {
			return NULL;
		} else {
			return frontAndPop(DOG);
		}
	}

	node* dequeueCat() {
		if(cats.size() == 0) {
			return NULL;
		} else {
			return frontAndPop(CAT);
		}
	}

	node* frontAndPop(int type) {
		node* toReturn;

		if(type == DOG) {
			toReturn = dogs.front();
			dogs.pop();
		} else {
			toReturn = cats.front();
			cats.pop();
		}

		return toReturn;
	}
};

int main() {
	animalQueue q;

	assert(q.dequeueAny() == NULL);
	assert(q.dequeueDog() == NULL);
	assert(q.dequeueCat() == NULL);

	q.push(new node(1, DOG));
	q.push(new node(2, DOG));
	q.push(new node(3, CAT));
	q.push(new node(4, DOG));
	q.push(new node(5, CAT));

	node* m;

	m = q.dequeueAny();
	assert(m->data == 1);

	m = q.dequeueCat();
	assert(m->data == 3);

	m = q.dequeueDog();
	assert(m->data == 2);

	m = q.dequeueCat();
	assert(m->data == 5);

	m = q.dequeueAny();
	assert(m->data == 4);

	cout << "success" << endl;

	return 0;
}