#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree; // 트리
vector<bool> visit; // 방문표시
vector<vector<int>> dp;

/**
 * dp에는 해당 정점을 루트로 가지는 서브 트리의 얼리어답터 최소 개수 저장
 * dp[x][0] : x 정점이 얼리어답터가 아닐 때, 자식 노드는 반드시 얼리어답터여야 함.
 * dp[x][1] : x 정점이 얼리어답터 일 때, 자식 노드가 얼리어답터이거나 아니어도 됨.
*/

void solution(int x) {

    visit[x] = true; // 방문 표시
    dp[x][1] = 1; // x노드를 얼리어답터로 놓고 최소 얼리어답터 수를 1로 초기화

    for (int i = 0; i < tree[x].size(); i++) { // x노드에 연결된 모든 정점 방문
        int child = tree[x][i];
        if (!visit[child]) { // 방문하지 않은 경우
            solution(child);
            dp[x][0] += dp[child][1]; //현재 정점이 얼리어답터가 아닐 때
            dp[x][1] += min(dp[child][0], dp[child][1]); //현재 정점이 얼리어답터 일 때
        }
    }

}

int main() {

    //입력
    int n;
    cin >> n;

    tree.assign(n + 1, vector<int>(0));
    visit.assign(n + 1, 0);
    dp.assign(n + 1, vector<int>(2, 0));
    int u, v;

    // 트리만들기
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    //연산
    solution(1);

    //출력
    cout << min(dp[1][0], dp[1][1]);
    return 0;
}