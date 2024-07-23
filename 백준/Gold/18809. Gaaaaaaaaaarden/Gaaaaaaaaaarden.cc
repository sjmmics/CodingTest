#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N, M, G, R, res;
int DX[4] = { 1, -1, 0, 0 };
int DY[4] = { 0, 0, 1, -1 };
vector<vector<pair<int, int>>> vstd;
vector<bool> color_vstd;
vector<vector<int>> grp;
vector<pair<int, int>> strt_points;
queue<pair<int, int>> que;
vector<pair<int, pair<int, int>>> picked;

void bfs() {
    vstd.assign(N, vector<pair<int, int>>(M, { 0, 0 }));
    for (int i = 0; i < picked.size(); i++) {
        int color = picked[i].first;
        int row = picked[i].second.first;
        int col = picked[i].second.second;
        vstd[row][col] = { color, 1 };
        que.push({ row, col });
    }
    int cnt = 0;
    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        if (vstd[x][y].first == 3) continue;
        for (int i = 0; i < 4; i++) {
            int nx = x + DX[i];
            int ny = y + DY[i];
            if (nx < 0 || N <= nx || ny < 0 || M <= ny) {
                continue;
            }
            if (grp[nx][ny] == 0 || vstd[nx][ny].first == 3) {
                continue;
            }
            if (vstd[nx][ny].first != 0 && vstd[nx][ny].first == vstd[x][y].first) {
                continue;
            }
            if (vstd[nx][ny].first == 0) {
                vstd[nx][ny] = { vstd[x][y].first, vstd[x][y].second + 1 };
                que.push({ nx, ny });
            } else if (vstd[nx][ny].first != vstd[x][y].first && 
                            vstd[nx][ny].second == vstd[x][y].second + 1) {
                vstd[nx][ny].first = 3;
                cnt++;
            }
        }
    }
    res = max(res, cnt);
}

void pick_red(int bgn, int cnt) {
    if (cnt == R) {
        bfs();
        return;
    }
    for (int i = bgn; i < strt_points.size(); i++) {
        int x = strt_points[i].first;
        int y = strt_points[i].second;
        if (color_vstd[i]) continue;
        color_vstd[i] = true;
        picked.push_back({ 2, { x, y }});
        pick_red(i + 1, cnt + 1);
        picked.pop_back();
        color_vstd[i] = false;
    }

}

void pick_grn(int bgn, int cnt) {
    if (cnt == G) {
        pick_red(0, 0);
        return;
    }
    for (int i = bgn; i < strt_points.size(); i++) {
        int x = strt_points[i].first;
        int y = strt_points[i].second;
        if (color_vstd[i]) continue;
        color_vstd[i] = true;
        picked.push_back({ 1, { x, y }});
        pick_grn(i + 1, cnt + 1);
        picked.pop_back();
        color_vstd[i] = false;
    }
}

int solution() {
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grp[i][j] == 2) {
                strt_points.push_back({ i, j });
            }
        }
    }
    color_vstd.assign(strt_points.size(), false);
    pick_grn(0, 0);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> G >> R;
    grp.assign(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grp[i][j];
        }
    }
    cout << solution() << "\n";
}