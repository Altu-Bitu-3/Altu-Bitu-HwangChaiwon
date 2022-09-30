#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e8;

vector<bool> visited; //�湮 �˻� �迭
vector<vector<int>> matrix; //��� ���
int n, ans = INF; //�ּ� ��� ���� ���� �̸� �ִ����� �ʱ�ȭ

void backtracking(int cnt, int cur_city, int cost) {
    // �ּ� ����� ���ϴ� ���̹Ƿ� ����� ans ���� ũ�� ����
    if (cost >= ans) {
        return;
    }
    if (cnt == n) { //���� ���� : n���� ���ø� ��ȸ����
        //��� ����(0)�� �ٽ� ���ƿ� �� �ִ��� Ȯ��
        //����� 0 �̸� ��ߵ��÷� �ٽ� ���ƿ� �� �����Ƿ� ������ '0�� �ƴ� ���'�� �����Ѵ�
        if (matrix[cur_city][0] != 0) {
            // ó�� ���÷� ���ƿͼ� ans�� ��� ����
            ans = min(ans, cost + matrix[cur_city][0]);
        }
        return;
    }
    for (int i = 0; i < n; i++) { //cur_city���� ���� i�� �̵�
        if (matrix[cur_city][i] && !visited[i]) { //���� �ְ�, ���� �湮���� ���� ����
            // �湮�� ���ø� ture�� �ٲ��ش�.
            visited[i] = true;
            // ����� ���ϰ� count �������Ѽ� ���� ���� ��ȸ
            backtracking(cnt + 1, i, cost + matrix[cur_city][i]);
            // �ٽ� ���ƿ� ��� false�� �ٲ��ش�.
            visited[i] = false;
        }
    }
}

/**
 * ��Ʈ��ŷ Ǯ�� (4ms)
 * �� ����Ŭ�� �����, ��� ���ÿ��� �����ϵ� ���� �����Ƿ� 0�� ���ú��� �����ϴ� ��츸 �˻��ϸ� �ȴ�.
 */

int main() {

    //�Է�
    cin >> n;
    visited.assign(n, false); // �湮�˻������ �ʱ�ȭ�Ѵ�
    matrix.assign(n, vector<int>(n, 0)); // �������� �ʱ�ȭ�Ѵ�
    // �����Ŀ� �Է�
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    //����
    visited[0] = true;
    backtracking(1, 0, 0);

    //���
    cout << ans;
    return 0;
}







//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//int const MAX = 10;
//int n;
//vector<vector<int>> W;
//vector<bool> check(10, false);
//vector<int> price;
//int sum;
//int result;
//
//int getTSP(int cnt) {
//	if (cnt == n) {
//		for (int i = 0; i < cnt; i++) {
//			sum += price[i];
//		}
//		result = min(result, sum);
//		return result;
//	}
//	int temp;
//	for (int i = 0; i < n; i++) {
//		if (!check[i]) {
//			price[cnt] = W[cnt][i]
//			check[i] = true;
//			getTSP(cnt + 1);
//			check[i] = false;
//		}
//	}
//}
//
//int main() {
//
//	cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> W[i][j];
//		}
//	}
//
//	cout << getTSP(0);
//	return 0;
//}