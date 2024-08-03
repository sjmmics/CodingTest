#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int grp[50][50];
int DX[4] = { 1, -1, 0, 0 };
int DY[4] = { 0, 0, 1, -1 };
vector<vector<bool>> vstd;

int bfs(int row, int col, int wl) {
    int ret = 0;
    bool flood = false;
    vstd[row][col] = true;
    queue<pair<int, int>> que;
    que.push({ row, col });
    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        ret++;
        grp[x][y]++;
        if (x == 0 || x == N - 1 || y == 0 || y == M - 1) {
            flood = true;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + DX[i];
            int ny = y + DY[i];
            if (nx < 0 || N <= nx || ny < 0 || M <= ny) {
                continue;
            }
            if (vstd[nx][ny]) continue;
            if (grp[nx][ny] != wl) continue;
            vstd[nx][ny] = true;
            que.push({ nx, ny });
        }
    }
    if (!flood) return ret;
    else return 0;
}


int solution() {
    int ret = 0;
    for (int wl = 1; wl <= 9; wl++) {
        vstd.assign(N, vector<bool>(M, false));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (vstd[i][j]) continue;
                if (grp[i][j] == wl) {
                    ret += bfs(i, j, wl);
                }
            }
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string line;  cin >> line;
        for (int j = 0; j < M; j++) {
            grp[i][j] = line[j] - '0';
        }
    }
    cout << solution() << "\n";
}