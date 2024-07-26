#include <iostream>
#include <vector>
#include <queue>
#define INF 2'000'000'000

using namespace std;

int N, K, M;
vector<vector<int>> grp;
int dstc[100'000 + 1'000];
bool vstd[100'000 + 1'000];

int bfs() {
    queue<int> que;
    que.push(0);
    vstd[0] = true;
    while (!que.empty()) {
        int crr = que.front();  que.pop();
        if (crr == N - 1) return dstc[crr];
        for (int nxt : grp[crr]) {
            if (vstd[nxt]) continue;
            vstd[nxt] = true;
            dstc[nxt] = dstc[crr] + 1;
            que.push(nxt);
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K >> M;
    grp.resize(N + M);
    for (int i = N; i < N + M; i++) {
        for (int j = 0; j < K; j++) {
            int x;  cin >> x;
            grp[i].push_back(x - 1);
            grp[x - 1].push_back(i);
        }
    }

    int res = bfs();
    if (res != -1) {
        res = res / 2 + 1;
    }
    cout << res << "\n";
}