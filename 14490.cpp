#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// 유클리드 호제법
int gcdRecursion(int a, int b) {
	// a > b 일 때, a와 b의 최대공약수를 리턴
	if (b == 0) {
		return a;
	}
	return gcdRecursion(b, a % b);
}


int main() {
	string str;
	cin >> str;
	
	string str1 = str.substr(0, str.find(':'));
	string str2 = str.substr(str.find(':') + 1);

	int n = stoi(str1);
	int m = stoi(str2);

	int gcd = gcdRecursion(n, m);
	cout << n / gcd << ":" << m / gcd;
	return 0;
}