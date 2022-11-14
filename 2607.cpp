#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

vector<string> s;
int similarWord(vector<string>& s) {
	string strdef = s[0];
	int words = 0;
	for (int i = 1; i < s.size(); i++) {
		int cnt = 0;
		string strvar = s[i];
		int l = strvar.length() - strdef.length();
		// 길이 차이 2 이상이면 버리기
		if (abs(l) > 1) {
			continue;
		}
		// 길이차이 0이면
		else if (l == 0) {
			// find로 검사
			for (int i = 0; i < strdef.length(); i++) {
				if (strvar.find(strdef[i]) == string::npos) {
					cnt++;
				}
			}
			if (cnt <= 1) {
				words++;
			}
		}
		// 길이차이 1이면
		else if (l == 1){
			// find로 검사
			for (int i = 0; i < strdef.length(); i++) {
				if (strvar.find(strdef[i]) == string::npos) {
					cnt++;
				}
			}
			if (cnt == 0) {
				words++;
			}
		}
		else if (l == -1) {
			// find로 검사
			for (int i = 0; i < strdef.length(); i++) {
				if (strvar.find(strdef[i]) == string::npos) {
					cnt++;
				}
			}
			if (cnt <= 1) {
				words++;
			}
		}
	}
	return words;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		s.push_back(str);
	}
	cout << similarWord(s);
	return 0;
}