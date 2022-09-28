#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 8;
int n, m;
// n 개의 수 중에서 m 길이의 수열 구하기
vector<int> num(MAX);
vector<int> arr(MAX);
vector<bool> check(MAX);

void backtracking(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < cnt; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	int temp = 0;
	for (int i = 0; i < n; i++) {
		if (!check[i] && temp != num[i]) {
			arr[cnt] = num[i];
			temp = num[i];
			check[i] = true;
			backtracking(cnt + 1);
			// 다시 돌아왔을 떄 
			check[i] = false;
		}
	}
}


int main() {

	cin >> n >> m;
	
	// n 개의 수를 입력받는다
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	// 오름차순 정렬
	sort(num.begin(), num.begin() + n);

	backtracking(0);

	return 0;
}