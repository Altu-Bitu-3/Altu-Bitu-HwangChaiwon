#include <iostream>
#include <string>
#include <stack>
using namespace std;

string getPassword(string s) {

	stack<char> front;
	stack<char> back;

	while (!front.empty()) {
		front.pop();
	}
	while (!back.empty()) {
		back.pop();
	}

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '<') {
			if (!front.empty()) {
				back.push(front.top());
				front.pop();
			}
		}

		else if (s[i] == '>') {
			if (!back.empty()) {
				front.push(back.top());
				back.pop();
			}
		}

		else if (s[i] == '-') {
			if (!front.empty()) {
				front.pop();
			}
		}

		else {
			// 영문자 입력
			front.push(s[i]);
		}
	}

	while (!front.empty()) {
		back.push(front.top());
		front.pop();
	}

	string password;

	while (!back.empty()) {
		password += back.top();
		back.pop();
	}

	return password;
}

int main() {
	int n;
	cin >> n;

	while (n--) {
		string s;
		cin >> s;
		cout << getPassword(s) << '\n';
	}


	return 0;
}