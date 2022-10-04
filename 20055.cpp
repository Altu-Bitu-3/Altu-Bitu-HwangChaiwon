// ���� ���� ��Ʈ�� �ö� �κ�����, ��Ʈ�� ȸ���ϴ� �������� �� ĭ �̵��� �� �ִٸ� �̵��Ѵ�
// �� ������ ��Ʈ���� https://yabmoons.tistory.com/599 �����Ͽ� ����
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> belt; // ������ ����
vector<bool> robot; // �κ��� ������ �������� ����

queue<int> sequence;

int start_idx, end_idx; // Ÿ�� ��, ������ ���� �ε���

int getLevel(int n, int k) {
	int level = 1;
	int x = 0;
	while (true) {
		// �����̾� ��Ʈ�� ȸ���Ѵ�
		start_idx--;
		end_idx--;
		if (start_idx < 0) { start_idx = 2 * n - 1; }
		if (end_idx < 0) { end_idx = 2 * n - 1; }
		// ȸ�� �� �κ� ������
		if (robot[end_idx] == true) {
			robot[end_idx] = false;
		}

		// �κ� �̵�
		//for (int i = 0; i < robot.size(); i++) {
		//	if (i == (robot.size() - 1)) {
		//		if (robot[i] == true && robot[0] == false && belt[0] > 0) {
		//			robot[i] = false;
		//			robot[0] = true;
		//			belt[0]--;
		//			// �κ� ������
		//			if (end_idx == 0) {
		//				robot[end_idx] = false;
		//			}
		//		}
		//	}
		//	else {
		//		if (robot[i] == true && robot[i + 1] == false && belt[i + 1] > 0) {
		//			robot[i] = false;
		//			robot[i + 1] = true;
		//			belt[i + 1]--;
		//			// �κ� ������
		//			if (end_idx == i + 1) {
		//				robot[end_idx] = false;
		//			}
		//		}
		//	}
		//	
		//	
		//}
		
		
		// �κ� �̵�(�߰�)
		for (int i = 0; i < sequence.size(); i++) {
			int cur = sequence.front();
			robot[cur] = false;
			sequence.pop();

			if (cur == end_idx) continue;

			int next = cur + 1;
			if (next > 2 * n - 1) next = 0;
			if (belt[next] >= 1 && robot[next] == false) {
				belt[next]--;
				if (next == end_idx) continue;
				robot[next] = true;
				sequence.push(next);
			}
			else {
				robot[cur] = true;
				sequence.push(cur);
			}
		}

		// �κ� �ø���
		if (belt[start_idx] > 0 && robot[start_idx] == false) {
			robot[start_idx] = true;
			belt[start_idx]--;
			sequence.push(start_idx);
		}

		// �˻�
		for (int i = 0; i < belt.size(); i++) {
			if (belt[i] == 0) {
				x++;
			}
			else {
				continue;
			}
		}
		
		if (x == k) {
			break;
		}

		level++;
	}
	

	return level;
}

int main() {

	int n, k;

	cin >> n >> k;

	// ������, �κ� �迭 �ʱ�ȭ
	// 0 ~ 2n-1 �ӿ� ����
	for (int i = 0; i < 2 * n; i++) {
		int temp;
		cin >> temp;
		belt.push_back(temp);
		robot.push_back(false);
	}

	// �ε��� �ʱ�ȭ
	// �ε����� ������Ű�� ���
	start_idx = 0;
	end_idx = n - 1;

	// ���
	cout << getLevel(n, k);

	return 0;
}
