#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 8;
int n, m;
// n ���� �� �߿��� m ������ ���� ���ϱ�
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
			// �ٽ� ���ƿ��� �� 
			check[i] = false;
		}
	}
}


int main() {

	cin >> n >> m;
	
	// n ���� ���� �Է¹޴´�
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	// �������� ����
	sort(num.begin(), num.begin() + n);

	backtracking(0);

	return 0;
}