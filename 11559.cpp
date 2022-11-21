#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
//행과 열을 바꿔줄 것이므로 ROW를 6으로 설정
const int ROW = 6;
const int COL = 12;

// 뿌요가 터지면 true 반환한다.
bool bfs(int r, int c, vector<vector<char>>& board) {
    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };
    // 좌 우 상 하
    queue<ci> q;
    queue<ci> puyo; //포함된 좌표 저장할 큐
    vector<vector<bool>> visited(ROW, vector<bool>(COL, false));

    //시작 초기화
    q.push({ r, c });
    puyo.push({ r, c });
    visited[r][c] = true;
    int cnt = 1; //모여있는 뿌요의 개수
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (nr < 0 || nr >= ROW || nc < 0 || nc >= COL || visited[nr][nc]) {
                continue;
            } // 보드를 벗어나거나 방문한 위치일 경우 패스
            if (board[nr][nc] == board[cr][cc]) {
                q.push({ nr, nc });
                puyo.push({ nr, nc }); 
                visited[nr][nc] = true;
                cnt++;
            }
        }
    }
    if (cnt < 4) { //뿌요 안터짐
        return false;
    }
    while (!puyo.empty()) {
        int cr = puyo.front().first;
        int cc = puyo.front().second;
        puyo.pop();

        board[cr][cc] = '.'; // 뿌요를 터뜨린다
    }
    return true;
}

//뿌요를 터뜨린 이후의 새 필드를 작성하는 함수
vector<vector<char>> makeNewBoard(vector<vector<char>>& board) {
    vector<vector<char>> new_board(ROW, vector<char>(COL, '.')); // 점으로 초기화
    for (int i = 0; i < ROW; i++) {
        queue<char> temp; //남아있는 뿌요 모으는 큐
        for (int j = 0; j < COL; j++) {
            if (board[i][j] != '.') {
                temp.push(board[i][j]); // 같은 줄에 있는 뿌요를 큐에 넣는다
            }
        }
        int index = 0;
        while (!temp.empty()) {
            new_board[i][index++] = temp.front();
            temp.pop(); // 큐가 빌 때까지 새로운 보드에 채워넣기 (큐는 선입선출)
        }
    }
    return new_board;
}

int simulation(vector<vector<char>>& board) {
    int answer = 0;
    while (true) {
        bool flag = false; //뿌요가 터졌는지 확인
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (board[i][j] == '.') { // 뿌요가 없는 자리는 틍과
                    continue;
                }
                if (bfs(i, j, board)) { //한 번이라도 뿌요 터졌다면
                    flag = true;
                }
            }
        }
        if (!flag) { // 다 돌았는데 false이면 break
            break;
        }
        board = makeNewBoard(board); // 뿌요가 터졌다면 남은 뿌요를 모은다
        answer++; // 뿌요가 터졌으므로 연쇄 증가
    }
    return answer;
}

/**
 * [Puyo Puyo] - bfs, 시뮬레이션 문제
 *
 * 1. bfs 탐색을 통해 4개 이상의 뿌요가 모였는지 확인
 * 2. 4개 이상의 뿌요가 모였다면, 해당되는 영역을 '.'으로 바꾸어 비워줌
 * 3. 전체 필드에 대해 1~2를 다 수행한 후, 뿌요를 떨어뜨림
 *    - 바닥부터 시작해서 남아있는 뿌요들을 모으고, 남은 부분은 '.'으로 채우는 방식
 * 4. 터뜨릴 수 없을 때까지 반복
 *
 * 여기서, 3번 과정을 편하게 하기 위해 12*6으로 들어오는 입력을 6*12로 바꾸어준다.
 * 같은 열에 있는 데이터를 다루는 것보다 같은 행에 있는 데이터를 다루는 것이 편하기 때문이다.
 */

int main() {
    //입력
    char input;
    vector<vector<char>> board(ROW, vector<char>(COL));
    for (int i = 0; i < COL; i++) {
        for (int j = 0; j < ROW; j++) {
            cin >> input;
            board[j][COL - i - 1] = input;
        }
    }
    // 우측하단이 (0, 0)
    
    //연산 & 출력
    cout << simulation(board);
    return 0;
}