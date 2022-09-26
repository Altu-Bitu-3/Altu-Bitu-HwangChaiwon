#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool wordchecker(string s) {
	vector<bool> check(26, false);
	char temp;

	for (int i = 0; i < s.length(); i++) {
		if (check[s[i] - 'a'] == false) {
			check[s[i] - 'a'] = true;
		}
		else {
			if (temp != s[i]) {
				return false;
			}
		}
		temp = s[i];
	}
	return true;
}

int main() {
	vector<bool> check(26, false);
	int n;
	cin >> n;

	int count = 0;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (wordchecker(s) == true) {
			count++;
		}
	}

	cout << count;

	return 0;
}