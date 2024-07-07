#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int moves[10];
int res;
int points[75];
int board[75];
int tokens[5];
void init();
int get_nxt_pos(int crr, int step);

void dfs(int depth, int score) {
    // 종료 조건
    if (depth == 10) {
        res = max(score, res);
        return;
    }
    // 이동할 말을 하나 고른다.
    for (int i = 1; i < 5; i++) {
        int step = moves[depth];
        int crr_pos = tokens[i];
        
        // 말이 도착했으면 다른 말 이동
        if (crr_pos == 21) continue;
        
        // 이동할 말의 위치에서 이번에 이동할 칸을 더한 뒤 칸에 다른 말이 있는지 확인
        int nxt_pos = get_nxt_pos(crr_pos, step);
        bool occupied = false;
        for (int j = 1; j < 5; j++) {
            if (i != j && tokens[j] == nxt_pos) {
                occupied = true;
                break;
            }
        }
        if (nxt_pos != 21 && occupied) continue;
        
        // 이동
        tokens[i] = nxt_pos;

        dfs(depth + 1, score + points[nxt_pos]);
        
        // 이동 전으로 복원

        tokens[i] = crr_pos;
    }
    
}

int main() {
    init();
    
    for (int i = 0; i < 10; i++) {
        cin >> moves[i];
    }
    dfs(0, 0);

    cout << res << endl;
}

void init() {
    for (int i = 1; i < 21; i++) {
        points[i] = i * 2;
    }
    int temp1[7] = { 13, 16, 19, 25, 30, 35, 40 };
    for (int i = 0; i < 7; i++) {
        points[31 + i] = temp1[i]; 
    }
    int temp2[2] = { 22, 24 };
    for (int i = 0; i < 2; i++) {
        points[52 + i] = temp2[i];
    }
    int temp3[3] = { 28, 27, 26 };
    for (int i = 0; i < 3; i++) {
        points[71 + i] = temp3[i];
    }
}

int get_nxt_pos(int crr, int step) {
    int nxt = 0;
    // 파란색 분기점 시작일 때
    if (crr == 5) {
        nxt = 30 + step;
    } else if (crr == 10) {
        nxt = 51 + step;
    } else if (crr == 15) {
        nxt = 70 + step;
    } else {
        nxt = crr + step;
    }
    // 내부 이동 구현
    if (53 < nxt && nxt < 71) {
        nxt -= 20;
    } else if (73 < nxt) {
        nxt -= 40;
    }
    if (nxt == 37) {
        nxt = 20;
    }
    // 도착했을 경우
    if ((20 < nxt && nxt < 30) || (37 < nxt && nxt < 52)) {
        return 21;
    } else {
        return nxt;
    }

}