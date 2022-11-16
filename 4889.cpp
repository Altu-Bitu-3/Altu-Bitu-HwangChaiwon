#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	string str;
	int n = 1;

	while (true) {
		int count = 0;
		cin >> str;
		if (str[0] == '-')
			break;
		
		stack<char> s;
		for (int i = 0; i < str.size(); i++) {
			char c = str[i];
			if (c == '}' && !s.empty() && s.top() == '{')
				s.pop();
			else
				s.push(c);
		}

		while (!s.empty()) {
			char c1 = s.top();
			s.pop();
			char c2 = s.top();
			s.pop();
			if (c1 == c2) count++;
			else count += 2;
		}

		cout << n << ". " << count << '\n';
		n++;
	}
	return 0;
}