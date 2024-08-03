#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct coin {
    int x1;
    int y1;
    int x2;
    int y2;
    int t;
    coin() {}
    coin(int R1, int C1, int R2, int C2, int T) : 
    x1(R1), y1(C1), x2(R2), y2(C2), t(T) {}
};

int N, M;
int DX[4] = { 1, -1, 0, 0 };
int DY[4] = { 0, 0, 1, -1 };
vector<vector<char>> grp;
vector<vector<bool>> vstd;

bool is_out(int row, int col) {
    return (N <= row || row < 0 || M <= col || col < 0);
}

int solution(vector<pair<int, int>> bgn) {
    queue<coin> que;
    que.push(coin(bgn[0].first, bgn[0].second, 
                bgn[1].first, bgn[1].second, 0));
    while (!que.empty()) {
        int x1 = que.front().x1;
        int y1 = que.front().y1;
        int x2 = que.front().x2;
        int y2 = que.front().y2;
        int min = que.front().t;
        que.pop();
        if (min >= 10) continue;
        for (int i = 0; i < 4; i++) {
            int nx1 = x1 + DX[i];
            int ny1 = y1 + DY[i];
            int nx2 = x2 + DX[i];
            int ny2 = y2 + DY[i];
            bool coin1_out = is_out(nx1, ny1);
            bool coin2_out = is_out(nx2, ny2);
            if ((coin1_out && !coin2_out) || (!coin1_out && coin2_out)) {
                return min + 1;
            }
            if (coin1_out && coin2_out) continue;
            if (nx1 == nx2 && ny1 == ny2) continue;
            if (grp[nx1][ny1] == '#') {
                nx1 = x1, ny1 = y1;
            }
            if (grp[nx2][ny2] == '#') {
                nx2 = x2, ny2 = y2;
            }
            que.push(coin(nx1, ny1, nx2, ny2, min + 1));
        }
    }
    return -1;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    vector<pair<int, int>> coins;
    grp.assign(N, vector<char>(M));
    vstd.assign(10, vector<bool>(4, false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grp[i][j];
            if (grp[i][j] == 'o') {
                coins.push_back({ i, j });
            }
        }
    }
    
    cout << solution(coins) << "\n";
}