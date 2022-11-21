#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree; // Ʈ��
vector<bool> visit; // �湮ǥ��
vector<vector<int>> dp;

/**
 * dp���� �ش� ������ ��Ʈ�� ������ ���� Ʈ���� �󸮾���� �ּ� ���� ����
 * dp[x][0] : x ������ �󸮾���Ͱ� �ƴ� ��, �ڽ� ���� �ݵ�� �󸮾���Ϳ��� ��.
 * dp[x][1] : x ������ �󸮾���� �� ��, �ڽ� ��尡 �󸮾�����̰ų� �ƴϾ ��.
*/

void solution(int x) {

    visit[x] = true; // �湮 ǥ��
    dp[x][1] = 1; // x��带 �󸮾���ͷ� ���� �ּ� �󸮾���� ���� 1�� �ʱ�ȭ

    for (int i = 0; i < tree[x].size(); i++) { // x��忡 ����� ��� ���� �湮
        int child = tree[x][i];
        if (!visit[child]) { // �湮���� ���� ���
            solution(child);
            dp[x][0] += dp[child][1]; //���� ������ �󸮾���Ͱ� �ƴ� ��
            dp[x][1] += min(dp[child][0], dp[child][1]); //���� ������ �󸮾���� �� ��
        }
    }

}

int main() {

    //�Է�
    int n;
    cin >> n;

    tree.assign(n + 1, vector<int>(0));
    visit.assign(n + 1, 0);
    dp.assign(n + 1, vector<int>(2, 0));
    int u, v;

    // Ʈ�������
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    //����
    solution(1);

    //���
    cout << min(dp[1][0], dp[1][1]);
    return 0;
}