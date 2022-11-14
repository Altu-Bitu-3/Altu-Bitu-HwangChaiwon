// https://11001.tistory.com/27 ����
#include <iostream>
#include <vector>
using namespace std;
vector<bool> visited(10, false);
vector<int> order(10); //���� ����
/**
 * [��Ʈ] �Է��� �׷��� ũ�� �ʳ׿�! ��� ����� ���� �� �غ��� �� �� ���ƿ�.
 *        3�ƿ��� �Ǹ� �ƿ� ī��Ʈ�� ����� ���ڵ��� ��� ���µǰ� ���ο� �̴��� ���۵ȴٴ� ��Ģ�� �� ������ּ���!
 */

 /* ����� ���ڵ��� ���� ������Ʈ */
int hit(vector<bool>& state, int n) {
    int score = 0;
    for (int i = 3; i > 0; i--) {
        if (!state[i]) {
            continue; //���ڰ� ������ �н�
        }
        state[i] = false; //���� ��ġ �̵�
        if (i + n >= 4) { //Ȩ���� ������ ���
            score++;
        }
        else {
            state[i + n] = true; //n��ŭ �̵��� �ڸ��� ���� ��ġ�� ������Ʈ
        }
    }
    //���� Ÿ���� ��ġ �����ϱ�
    if (n == 4) { //Ÿ�ڰ� Ȩ���� ������ ���
        return score + 1;
    }
    //��Ÿ�� ���� ���
    state[n] = true;
    return score;
}
/* Ÿ���� �������� �� ��⿡�� ��� ���� ���ϱ� */
int getScore(vector<vector<int>>& inning, int n) {
    int out = 0, score = 0, cur = 0;
    vector<bool> state(4, false); 
    int i = 1;
    while (true)
    {
        if (out == 3) { //3�ƿ�
            cur++; //���� �̴�
            out = 0;
            state = vector<bool>(4, false); //����� ���� ����
            continue;
        }
        if (cur == n) { //�̴� ����
            break;
        }

        int player = order[i++]; //Ÿ������ ���� ����
        i = i % 9 + 1; // �̴� �Ѿ�� ������ �����ȴ�.
        if (inning[cur][player] == 0) { //�ƿ�
            out++;
            continue;
        }
        score += hit(state, inning[cur][player]);
    }
    return score;
}
/* Ÿ�� ���ϱ� */
void game(int cnt, int n, vector<vector<int>>& inning, int& maxScore) {
    if (cnt == 4) { //4��° Ÿ�ڴ� 1�� ����
        game(cnt + 1, n, inning, maxScore); //���ο��� �������Ƿ� �ٷ� �������� �Ѿ��
    }
    else if (cnt == 10) { //9���� Ÿ�� ���� ������ ���
        int score = getScore(inning, n); //�������
        if (score > maxScore) { //����� ���� ���ؼ� �ִ밪 ������Ʈ�ϱ�
            maxScore = score;
        }
    }
    else {
        for (int i = 2; i <= 9; i++) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            order[cnt] = i;
            game(cnt + 1, n, inning, maxScore);
            visited[i] = false;
        }
    }
}
int main() {
    int n; cin >> n; //�̴� Ƚ��
    int score, maxScore = 0;
    vector<vector<int>> inning(n, vector<int>(10)); //Ÿ�ڵ��� �� �̴׿��� ��� ���
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> inning[i][j];
        }
    }
    order[4] = 1; //1�� ������ 4�� Ÿ�ڷ� ����
    visited[1] = true;

    game(1, n, inning, maxScore);
    cout << maxScore;
    return 0;
}