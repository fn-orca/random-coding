#include<bits/stdc++.h>

using namespace std;

typedef std::uint8_t byte;

// x1, x2, and y are 0-based
// x1 <= x2

void drawLine(vector<byte> &screen, int width, int x1, int x2, int y) {
	int yOffset = (width / 8) * y;

	int startIndex = yOffset + (x1 / 8);
	int startBit = x1 % 8;

	int finalIndex = yOffset + (x2 / 8);
	int finalBit = x2 % 8;

	if(startIndex == finalIndex) {
		int ones = (1 << (x2 - x1 + 1)) - 1;
		screen[startIndex] = ones << (8 - finalBit -1);
	} else {
		for(int i = startIndex; i <= finalIndex; i++) {
			if(i == startIndex) {
				int ones = 8 - startBit;
				screen[i] = (1 << ones) - 1;
			}
			if(i == finalIndex) {
				int aux = finalBit + 1;
				int ones = (1 << aux) - 1;
				screen[i] = ones << (8 - aux);
			}
			if(i > startIndex && i < finalIndex) {
				screen[i] = (1 << 7) | ((1 << 7) - 1);
			}
		}
	}
}

void printScreen(vector<byte> &screen, int width) {
	int i = 0;
	int c = width / 8;

	while(i < screen.size()) {
		for(int k = 0; k < c; k++) {
			bitset<8> b(screen[i+k]);
			cout << b;
		}

		cout << endl;
		i += c;
	}
}

void test0() {
	int width = 16;
	vector<byte> screen(6);

	drawLine(screen, width, 5, 12, 1);
	printScreen(screen, width);
	cout << endl;
}

int main() {
	test0();

	cout << "success" << endl;

	return 0;
}