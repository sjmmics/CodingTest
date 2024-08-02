#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <set>

using namespace std;
int DX[4] = { 1, -1, 0, 0 };
int DY[4] = { 0, 0, 1, -1 };
int arr[1'000][1'000];
int shape[1'000][1'000];
bool vstd[1'000][1'000];
map<int, int> dict;
int N, M;

void bfs(int sr, int sc, int shape_cnt) {
    int bgst = 0;
    queue<pair<int, int>> que;
    vector<pair<int, int>> vt;
    vt.push_back({ sr, sc });
    que.push({ sr, sc });
    vstd[sr][sc] = true;
    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        bgst++;
        for (int i = 0; i < 4; i++) {
            int nx = x + DX[i];
            int ny = y + DY[i];
            if (N <= nx || nx < 0 || M <= ny || ny < 0) {
                continue;
            }
            if (vstd[nx][ny]) continue;
            if (arr[nx][ny] == 0) continue;
            vstd[nx][ny] = true;
            que.push({ nx, ny });
            vt.push_back({ nx, ny });
        }
    }
    for (pair<int, int> crr : vt) {
        int x = crr.first;
        int y = crr.second;
        shape[x][y] = shape_cnt;
    }
    dict.insert({ shape_cnt, bgst });
}

int get_size_shape(int x, int y) {
    int ret = 1;
    set<int> temp;
    for (int i = 0; i < 4; i++) {
        int nx = x + DX[i];
        int ny = y + DY[i];
        if (N <= nx || nx < 0 || M <= ny || ny < 0) {
            continue;
        }
        if (shape[nx][ny] != 0) {
            temp.insert(shape[nx][ny]);
        }
    }
    set<int>::iterator iter;
    for (iter = temp.begin(); iter != temp.end(); iter++) {
        ret += dict[*iter];
    }
    return ret;
}

int solution() {
    int cnt = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 1 && shape[i][j] == 0) {
                bfs(i, j, cnt);
                cnt++;
            }
        }
    }
    int res = 0;
    map<int, int>::iterator iter;
    for (iter = dict.begin(); iter != dict.end(); iter++) {
        res = max(res, iter->second);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (shape[i][j] != 0) continue;
            res = max(res, get_size_shape(i, j));
        }
    }
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    cout << solution() << "\n";
}