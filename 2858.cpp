#include <iostream>

using namespace std;

int getSize(int r, int b) {
	int x;
	for (int i = 2; i <= r / 2 - 2; i++) {
		if ((i - 1) * (r / 2 - i - 1) == b) {
			x = i + 1;
			break;
		}
	}
	
	return x;
}
int main() {

	int r, b;
	int x, y;
	cin >> r >> b;

	x = getSize(r, b);
	y = r / 2 - x + 2;

	cout << max(x, y) << " " << min(x, y);
	return 0;
}