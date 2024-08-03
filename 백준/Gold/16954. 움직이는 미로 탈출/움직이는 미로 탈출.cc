#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321

using namespace std;

int N = 8;
// (1, 1) (1, 0), (1, -1), (0, -1), (-1, -1) (-1, 0), (-1, 1), (0, 1)
int DX[9] = { 0, 1, 1, 1, 0, -1, -1, -1, 0 };
int DY[9] = { 0, 1, 0, -1, -1, -1, 0, 1, 1 };
vector<vector<vector<bool>>> grp;
vector<vector<bool>> wall;

int bfs() {
    queue<pair<pair<int, int>, int>> que;
    que.push({ { N - 1, 0 }, 0 });
    grp[N - 1][0][0] = true;
    while (!que.empty()) {
        int x = que.front().first.first;
        int y = que.front().first.second;
        int t = que.front().second;
        que.pop();
        if (x == 0) return 1;
        for (int i = 0; i < 9; i++) {
            int nx = x + DX[i];
            int ny = y + DY[i];
            if (N <= nx || nx < 0 || N <= ny || ny < 0) {
                continue;
            }
            if (0 <= nx - (t + 1) && nx - (t + 1) < N && wall[nx - t - 1][ny]) continue;
            if (0 <= nx - t && nx - t < N && wall[nx - t][ny]) continue;
            if (grp[nx][ny][t + 1]) continue;
            grp[nx][ny][t + 1] = true;
            que.push({ { nx, ny }, t + 1});
        }
    }
    return 0;
}

int main() {
    grp.assign(N, vector<vector<bool>>(N, vector<bool>(9, false)));
    wall.assign(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char x;  cin >> x;
            if (x == '#') {
                wall[i][j] = true;
            }
        }
    }
    cout << bfs() << "\n";
}