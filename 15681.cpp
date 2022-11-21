// https://kibbomi.tistory.com/206 �����߽��ϴ�.

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree;
vector<int> sub;

int dfs(int parent, int cur) {
	int subtreenum = 0;
	// range based for loops
	// array�� ��Ҹ� �ݺ��Ѵ�
	for (int next : tree[cur]) {
		if (next == parent) {
			continue;
		}
		subtreenum += dfs(cur, next);
	}
	return sub[cur] = subtreenum + 1;
}
int main() {
	int u, v;
	int N, R, Q;
	cin >> N >> R >> Q;

	tree.assign(N + 1, vector<int>(0));
	sub.assign(N + 1, 0);
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	dfs(0, R);

	for (int i = 0; i < Q; i++) {
		int q;
		cin >> q;
		cout << sub[q];
	}
	return 0;
}