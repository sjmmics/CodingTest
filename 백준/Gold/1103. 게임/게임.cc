#include <iostream>
#include <vector>

using namespace std;

int N, M;
int DX[] = { 1, -1, 0, 0 };
int DY[] = { 0, 0, 1, -1 };
vector<vector<char>> board;
vector<vector<bool>> vstd;
vector<vector<int>> dpt;
bool is_inf = false;

int dfs(int x, int y) {
    if (is_inf) return 0;
    if (vstd[x][y]) {
        is_inf = true;
        return 0;
    }
    if (board[x][y] == 'H') {
        return 0;
    }
    vstd[x][y] = true;
    int bgst = 0;
    for (int i = 0; i < 4; i++) {
        int delta = board[x][y] - '0';
        int nx = x + delta * DX[i];
        int ny = y + delta * DY[i];
        if (nx < 0 || N <= nx || ny < 0 || M <= ny) {
            bgst = max(bgst, 1);
            continue;
        }
        if (dpt[nx][ny] != -1) {
            bgst = max(bgst, dpt[nx][ny] + 1);
        } else {
            bgst = max(bgst, dfs(nx, ny) + 1);
        }
    }
    vstd[x][y] = false;
    dpt[x][y] = bgst; 
    return dpt[x][y];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    board.assign(N, vector<char>(M));
    vstd.assign(N, vector<bool>(M, false));
    dpt.assign(N, vector<int>(M, -1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    dfs(0, 0);
    if (is_inf) cout << -1 << "\n";
    else cout << dpt[0][0] << "\n";
}
