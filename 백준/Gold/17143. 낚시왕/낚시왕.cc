#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef struct shark {
    int size;
    int speed;
    int direction;
    shark(int X, int Y, int Z) : size(X), speed(Y), direction(Z) {}
} shark;

bool compare_shark(shark &a, shark &b) {
    return a.size > b.size;
}

int R, C, M, res;
vector<vector<vector<shark>>> vt;
vector<pair<int, int>> alive;

pair<pair<int, int>, int> calc(int x, int y, int direction, int delta) {
    if (direction == 0 || direction == 1) {
        if (x == 0) {
            direction = 1;
        } else if (x == R - 1) {
            direction = 0;
        }
    } else {
        if (y == 0) {
            direction = 2;
        } else if (y == C - 1) {
            direction = 3;
        }
    }
    
    if (direction == 0) {
        if (delta <= x) {
            return { { x - delta, y }, direction };
        }
        delta -= x;
        x = 0;
        delta %= (2 * (R - 1));
        if (delta <= R - 1) {
            return { { x + delta, y }, 1 };
        } else {
            delta -= R - 1;
            return { { R - 1 - delta, y }, 0 };
        }
    } else if (direction == 1) {
        delta += x;
        x = 0;
        delta %= (2 * (R - 1));
        if (delta <= R - 1) {
            return { { x + delta, y }, 1 };
        } else {
            delta -= R - 1;
            return { { R - 1 - delta, y }, 0 };
        }
    } else if (direction == 2) {
        delta += y;
        y = 0;
        delta %= (2 * (C - 1));
        if (delta <= C - 1) {
            return { { x, y + delta }, 2 };
        } else {
            delta -= C - 1;
            return { { x, C - 1 - delta }, 3 };
        }
    } else {
        if (delta <= y) {
            return { { x, y - delta }, direction };
        }
        delta -= y;
        y = 0;
        delta %= (2 * (C - 1));
        if (delta <= C - 1) {
            return { { x, y + delta }, 2};
        } else {
            delta -= C - 1;
            return { { x, C - 1 - delta }, 3 };
        }
    }
}

void shark_move() {
    vector<vector<vector<shark>>> nxt_vt;
    nxt_vt.assign(R, vector<vector<shark>>(C, vector<shark>()));
    for (pair<int, int> p : alive) {        
        int x = p.first;
        int y = p.second;
        if (vt[x][y].size() == 0) continue;
        shark crr = vt[x][y][0];
        pair<pair<int, int>, int> nxt = calc(x, y, crr.direction, crr.speed);
        int nx = nxt.first.first;
        int ny = nxt.first.second;
        int nd = nxt.second;
        nxt_vt[nx][ny].push_back(shark(crr.size, crr.speed, nd));
    }
    vt.assign(R, vector<vector<shark>>(C, vector<shark>()));
    alive.clear();
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (nxt_vt[i][j].size() == 0) continue;
            if (nxt_vt[i][j].size() > 1) {
                sort(nxt_vt[i][j].begin(), nxt_vt[i][j].end(), compare_shark);
            }
            vt[i][j].push_back(nxt_vt[i][j][0]);
            alive.push_back({ i, j });
        }
    }
}

int solution() {
    for (int j = 0; j < C; j++) {
        for (int i = 0; i < R; i++) {
            if (vt[i][j].size() > 0) {
                res += vt[i][j][0].size;
                vt[i][j].clear();
                break;
            }
        }
        shark_move();        
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> R >> C >> M;
    vt.assign(R, vector<vector<shark>>(C, vector<shark>()));
    for (int i = 0; i < M; i++) {
        int r, c, s, d, sz;
        cin >> r >> c >> s >> d >> sz;
        r--, c--, d--;
        vt[r][c].push_back(shark(sz, s, d));
        alive.push_back({ r, c });
    }
    cout << solution() << "\n";
}