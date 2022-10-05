#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> present;

int givePresent(int n, int m) {
	int c;
	
	for (int i = 0; i < m; i++) {
		cin >> c;
		if (present.top() >= c) {
			present.push(present.top() - c);
			present.pop();
			continue;
		}
		else {
			return 0;
		}
	}
	return 1;
}
	
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		present.push(p);
	}

	cout << givePresent(n, m);
	return 0;
}