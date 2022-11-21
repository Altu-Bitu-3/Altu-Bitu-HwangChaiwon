#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
//��� ���� �ٲ��� ���̹Ƿ� ROW�� 6���� ����
const int ROW = 6;
const int COL = 12;

// �ѿ䰡 ������ true ��ȯ�Ѵ�.
bool bfs(int r, int c, vector<vector<char>>& board) {
    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };
    // �� �� �� ��
    queue<ci> q;
    queue<ci> puyo; //���Ե� ��ǥ ������ ť
    vector<vector<bool>> visited(ROW, vector<bool>(COL, false));

    //���� �ʱ�ȭ
    q.push({ r, c });
    puyo.push({ r, c });
    visited[r][c] = true;
    int cnt = 1; //���ִ� �ѿ��� ����
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (nr < 0 || nr >= ROW || nc < 0 || nc >= COL || visited[nr][nc]) {
                continue;
            } // ���带 ����ų� �湮�� ��ġ�� ��� �н�
            if (board[nr][nc] == board[cr][cc]) {
                q.push({ nr, nc });
                puyo.push({ nr, nc }); 
                visited[nr][nc] = true;
                cnt++;
            }
        }
    }
    if (cnt < 4) { //�ѿ� ������
        return false;
    }
    while (!puyo.empty()) {
        int cr = puyo.front().first;
        int cc = puyo.front().second;
        puyo.pop();

        board[cr][cc] = '.'; // �ѿ並 �Ͷ߸���
    }
    return true;
}

//�ѿ並 �Ͷ߸� ������ �� �ʵ带 �ۼ��ϴ� �Լ�
vector<vector<char>> makeNewBoard(vector<vector<char>>& board) {
    vector<vector<char>> new_board(ROW, vector<char>(COL, '.')); // ������ �ʱ�ȭ
    for (int i = 0; i < ROW; i++) {
        queue<char> temp; //�����ִ� �ѿ� ������ ť
        for (int j = 0; j < COL; j++) {
            if (board[i][j] != '.') {
                temp.push(board[i][j]); // ���� �ٿ� �ִ� �ѿ並 ť�� �ִ´�
            }
        }
        int index = 0;
        while (!temp.empty()) {
            new_board[i][index++] = temp.front();
            temp.pop(); // ť�� �� ������ ���ο� ���忡 ä���ֱ� (ť�� ���Լ���)
        }
    }
    return new_board;
}

int simulation(vector<vector<char>>& board) {
    int answer = 0;
    while (true) {
        bool flag = false; //�ѿ䰡 �������� Ȯ��
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (board[i][j] == '.') { // �ѿ䰡 ���� �ڸ��� �v��
                    continue;
                }
                if (bfs(i, j, board)) { //�� ���̶� �ѿ� �����ٸ�
                    flag = true;
                }
            }
        }
        if (!flag) { // �� ���Ҵµ� false�̸� break
            break;
        }
        board = makeNewBoard(board); // �ѿ䰡 �����ٸ� ���� �ѿ並 ������
        answer++; // �ѿ䰡 �������Ƿ� ���� ����
    }
    return answer;
}

/**
 * [Puyo Puyo] - bfs, �ùķ��̼� ����
 *
 * 1. bfs Ž���� ���� 4�� �̻��� �ѿ䰡 �𿴴��� Ȯ��
 * 2. 4�� �̻��� �ѿ䰡 �𿴴ٸ�, �ش�Ǵ� ������ '.'���� �ٲپ� �����
 * 3. ��ü �ʵ忡 ���� 1~2�� �� ������ ��, �ѿ並 ����߸�
 *    - �ٴں��� �����ؼ� �����ִ� �ѿ���� ������, ���� �κ��� '.'���� ä��� ���
 * 4. �Ͷ߸� �� ���� ������ �ݺ�
 *
 * ���⼭, 3�� ������ ���ϰ� �ϱ� ���� 12*6���� ������ �Է��� 6*12�� �ٲپ��ش�.
 * ���� ���� �ִ� �����͸� �ٷ�� �ͺ��� ���� �࿡ �ִ� �����͸� �ٷ�� ���� ���ϱ� �����̴�.
 */

int main() {
    //�Է�
    char input;
    vector<vector<char>> board(ROW, vector<char>(COL));
    for (int i = 0; i < COL; i++) {
        for (int j = 0; j < ROW; j++) {
            cin >> input;
            board[j][COL - i - 1] = input;
        }
    }
    // �����ϴ��� (0, 0)
    
    //���� & ���
    cout << simulation(board);
    return 0;
}