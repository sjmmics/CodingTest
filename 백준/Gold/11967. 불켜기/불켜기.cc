#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int N, M, res;
int DX[4] = { 1, -1, 0, 0 };
int DY[4] = { 0, 0, 1, -1 };
map< pair<int, int>, vector<pair<int, int>> > grp;
vector<vector<bool>> vstd;
vector<vector<bool>> light;

bool can_go_nxt(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + DX[i];
        int ny = y + DY[i];
        if (nx < 0 || N <= nx || ny < 0 || N <= ny) {
            continue;
        }
        if (vstd[nx][ny]) return true;
    }
    return false;
}

int bfs() {
    queue<pair<int, int>> que;
    que.push({ 0, 0 });
    vstd[0][0] = true;
    light[0][0] = true;
    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        for (int i = 0; i < grp[{ x, y }].size(); i++) {
            int row = grp[{ x, y }][i].first;
            int col = grp[{ x, y }][i].second;
            light[row][col] = true;
            if (vstd[row][col]) continue;
            if (can_go_nxt(row, col)) {                
                que.push({ row, col });
                vstd[row][col] = true;
            }
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + DX[i];
            int ny = y + DY[i];
            if (nx < 0 || N <= nx || ny < 0 || N <= ny) {
                continue;
            }
            if (vstd[nx][ny] || !light[nx][ny]) continue;
            vstd[nx][ny] = true;
            que.push({ nx, ny });
        }
    }
    int res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res += light[i][j];
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    vstd.assign(N, vector<bool>(N, false));
    light.assign(N, vector<bool>(N, false));
    while (M--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        x--; y--; a--; b--;
        grp[{ x, y }].push_back({ a, b });
    }
    cout << bfs() << "\n";
}