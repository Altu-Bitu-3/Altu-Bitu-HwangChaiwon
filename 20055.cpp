// 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다
// 위 조건을 빠트려서 https://yabmoons.tistory.com/599 참고하여 수정
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> belt; // 내구도 저장
vector<bool> robot; // 로봇이 탔는지 안탔는지 저장

queue<int> sequence;

int start_idx, end_idx; // 타는 곳, 내리는 곳의 인덱스

int getLevel(int n, int k) {
	int level = 1;
	int x = 0;
	while (true) {
		// 컨베이어 벨트가 회전한다
		start_idx--;
		end_idx--;
		if (start_idx < 0) { start_idx = 2 * n - 1; }
		if (end_idx < 0) { end_idx = 2 * n - 1; }
		// 회전 후 로봇 내리기
		if (robot[end_idx] == true) {
			robot[end_idx] = false;
		}

		// 로봇 이동
		//for (int i = 0; i < robot.size(); i++) {
		//	if (i == (robot.size() - 1)) {
		//		if (robot[i] == true && robot[0] == false && belt[0] > 0) {
		//			robot[i] = false;
		//			robot[0] = true;
		//			belt[0]--;
		//			// 로봇 내리기
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
		//			// 로봇 내리기
		//			if (end_idx == i + 1) {
		//				robot[end_idx] = false;
		//			}
		//		}
		//	}
		//	
		//	
		//}
		
		
		// 로봇 이동(추가)
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

		// 로봇 올리기
		if (belt[start_idx] > 0 && robot[start_idx] == false) {
			robot[start_idx] = true;
			belt[start_idx]--;
			sequence.push(start_idx);
		}

		// 검사
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

	// 내구도, 로봇 배열 초기화
	// 0 ~ 2n-1 임에 주의
	for (int i = 0; i < 2 * n; i++) {
		int temp;
		cin >> temp;
		belt.push_back(temp);
		robot.push_back(false);
	}

	// 인덱스 초기화
	// 인덱스를 증가시키는 방식
	start_idx = 0;
	end_idx = n - 1;

	// 출력
	cout << getLevel(n, k);

	return 0;
}
