#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define INT_MAX 2147483647
using namespace std;

void minecraft(int b, vector<vector<int>> &land) {
	int time = INT_MAX; // �ð�
	int height = 0; // ���� ����

	//�Է� ���� ���� ���̿��� �ִ�, �ּ� �˾Ƴ���
	int min = 256;
	int max = 0;
	for (int n = 0; n < land.size(); n++) {
		int tmp = *min_element(land[n].begin(), land[n].end());
		if (tmp <= min) {
			min = tmp;
		}
	}
	for (int n = 0; n < land.size(); n++) {
		int tmp = *max_element(land[n].begin(), land[n].end());
		if (tmp >= max) {
			max = tmp;
		}
	}

	// min ���� max ������ ���̿� ���纸�� �ִܽð� ���ϱ�
	for (int i = min; i <= max; i++) {
		int build = 0, remove = 0;
		// ������ �Ǵ� ���� i
		// i ���� ũ�� ���� ������ ���Ѵ�
		for (int j = 0; j < land.size(); j++) {
			for (int k = 0; k < land[j].size(); k++) {
				int diff = land[j][k] - i;
				if (diff < 0) {
					build += (-diff); // �ױ�
				}
				else {
					remove += diff; // �����ϱ�
				}
			}
		}

		if (build <= remove + b) {
			int tmp_time = build + remove * 2;
			if (tmp_time <= time) {
				time = tmp_time;
				height = i;
			}
		}
	}
	cout << time << " " << height;
}

int main() {
	int n, m, b;
	// �Է�
	cin >> n >> m >> b;
	vector<vector<int>> land(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> land[i][j];
		}
	}
	minecraft(b, land);

	return 0;
}