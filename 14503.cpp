#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int simulate(int n, int m, vector<vector<int>>& board, int r, int c, int d) {

	// �� �� �� �� 
	int dr[4] = { -1, 0, 1, 0, };
	int dc[4] = { 0, 1, 0, -1, };

	int ans = 0; // û���ϴ� ĭ�� ����

	while (true) {
		if (board[r][c] == 0) {
			board[r][c] = 2; //���� ��ġ û��
			ans++;
		}

		int step;
		//���� ���⿡ ���� û������ ���� ������ �����ִ���
		for (step = 0; step < 4; step++) {

			d = (d + 3) % 4;//���� ������ ���� ��ǥ
			//�� �������� ����(�ӽ�)
			int nr = r + dr[d];
			int nc = c + dc[d];

			if (!board[nr][nc]) { // û�ҵ��� ���� ���̶��
				// �� �������� ȸ���ϰ� ��ĭ�� ����(Ȯ��)
				r = nr;
				c = nc;
				break; // �ٽ� 1������ ����
			}
		}

		if (step == 4) { //�� ���� ��� ���̰ų� û�Ұ� �Ǿ��ִ� ���
			//�ٶ� ���� ������ ������ä�� �� ĭ ����
			r = r - dr[d];
			c = c - dc[d];
			if (board[r][c] == 1) { //���� ������ ���� ��� �۵� ���� 
				break;
			}
		}
	}
	return ans;
}

int main() {

	int n, m, r, c, d;
	cin >> n >> m >> r >> c >> d;
	vector<vector<int>> board(n, vector<int>(m, 0));

	//�Է�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	cout << simulate(n, m, board, r, c, d);

}