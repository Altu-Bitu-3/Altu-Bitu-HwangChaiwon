#include <iostream>
#include <string>
#include <vector>
using namespace std;

int getSize(string s) {
	int top = 0, bottom = 0, left = 0, right = 0;
	int dir = 0; // 방향
	vector<int> point(4, 0); // 북 동 남 서 시계방향

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'F') {
			point[dir % 4]++;
			point[(dir + 2) % 4]--;
		}
		else if (s[i] == 'B') {
			point[dir % 4]--;
			point[(dir + 2) % 4]++;
		}
		else if (s[i] == 'L') {
			dir += 3;
		}
		else if (s[i] == 'R') {
			dir++;
		}

		if (point[0] > top) {
			top = point[0];
		}
		if (point[1] > right) {
			right = point[1];
		}
		if (point[2] > bottom) {
			bottom = point[2];
		}
		if (point[3] > left) {
			left = point[3];
		}
	}
	
	int size = (top + bottom) * (right + left);
	return size;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		cout << getSize(s) << '\n';
	}

	return 0;
}