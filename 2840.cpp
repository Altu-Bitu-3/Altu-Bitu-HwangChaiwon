#include <iostream>
#include <vector>
using namespace std;

string getWheel(int n, int k) {
	vector<char> wheel(n, '?');
	vector<char> check(26, false);

	int point = 0;

	for (int i = 0; i < k; i++) {
		int cnt;
		char letter;
		cin >> cnt >> letter;
		cnt %= n;
		point -= cnt;
		if (point < 0) {
			point += n;
		}
		if (wheel[point] != '?' && wheel[point] != letter) {
			return "!";
		}
		else
			wheel[point] = letter;
	}

	for (int i = 0; i < wheel.size(); i++) {
		if (wheel[i] == '?')
			continue;
		if (check[wheel[i] - 'A'] == false) {
			check[wheel[i] - 'A'] = true;
		}
		else
			return "!";
	}

	string answer = "";

	for (int i = 0; i < wheel.size(); i++) {
		
		answer += wheel[(i + point)%n];
	}
	return answer;
}

int main() {
	int n, k;
	cin >> n >> k;

	cout << getWheel(n, k);

	return 0;
}