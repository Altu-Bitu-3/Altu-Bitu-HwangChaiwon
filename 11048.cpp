#include <iostream>
#include <vector>

using namespace std;

int n, m;

int getMax(int n, int m, vector<vector<int>> &candy, vector<vector<int>> &max_candy) {
	int ans;

	for (int i = 1; i < n+1; i++) {
		for (int j = 1; j < m+1; j++) {
			max_candy[i][j] = max(max(max_candy[i - 1][j], max_candy[i][j - 1]), max_candy[i - 1][j - 1]) + candy[i][j];
		}
	}

	ans = max_candy[n][m];

	return ans;
}

int main() {



	cin >> n >> m;

	vector<vector<int>> candy(n+1, vector<int>(m+1, 0));
	vector<vector<int>> max_candy(n+1, vector<int>(m+1, 0));

	// 입력
	for (int i = 1; i < n+1; i++) {
		for (int j = 1; j < m+1; j++) {
			cin >> candy[i][j];
		}
	}


	// 출력
	cout << getMax(n, m, candy, max_candy);


	return 0;
}