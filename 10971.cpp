#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e8;

vector<bool> visited; //방문 검사 배열
vector<vector<int>> matrix; //비용 행렬
int n, ans = INF; //최소 비용 저장 위해 미리 최댓값으로 초기화

void backtracking(int cnt, int cur_city, int cost) {
    // 최소 비용을 구하는 것이므로 비용이 ans 보다 크면 리턴
    if (cost >= ans) {
        return;
    }
    if (cnt == n) { //종료 조건 : n개의 도시를 순회했음
        //출발 도시(0)로 다시 돌아올 수 있는지 확인
        //비용이 0 이면 출발도시로 다시 돌아올 수 없으므로 조건을 '0이 아닐 경우'로 설정한다
        if (matrix[cur_city][0] != 0) {
            // 처음 도시로 돌아와서 ans에 비용 저장
            ans = min(ans, cost + matrix[cur_city][0]);
        }
        return;
    }
    for (int i = 0; i < n; i++) { //cur_city에서 도시 i로 이동
        if (matrix[cur_city][i] && !visited[i]) { //길이 있고, 아직 방문하지 않은 도시
            // 방문한 도시를 ture로 바꿔준다.
            visited[i] = true;
            // 비용을 더하고 count 증가시켜서 다음 도시 순회
            backtracking(cnt + 1, i, cost + matrix[cur_city][i]);
            // 다시 돌아온 경우 false로 바꿔준다.
            visited[i] = false;
        }
    }
}

/**
 * 백트래킹 풀이 (4ms)
 * 한 사이클을 만들면, 어느 도시에서 시작하든 값은 같으므로 0번 도시부터 시작하는 경우만 검사하면 된다.
 */

int main() {

    //입력
    cin >> n;
    visited.assign(n, false); // 방문검사행렬을 초기화한다
    matrix.assign(n, vector<int>(n, 0)); // 비용행렬을 초기화한다
    // 비용행렬에 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    //연산
    visited[0] = true;
    backtracking(1, 0, 0);

    //출력
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