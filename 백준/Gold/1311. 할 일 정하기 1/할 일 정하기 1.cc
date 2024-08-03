#include <iostream>
#define INF 987654321
using namespace std;

int N, cost[20][20];
int dpt[20][1 << 21];

int dfs(int crr, int vstd) {
    if (vstd == ((1 << N) - 1)) return 0;
    if (dpt[crr][vstd] != -1) return dpt[crr][vstd];
    dpt[crr][vstd] = INF;
    for (int nxt = 0; nxt < N; nxt++) {
        if (vstd & (1 << nxt)) continue;
        dpt[crr][vstd] = min(dpt[crr][vstd], 
                cost[crr][nxt] + dfs(crr + 1, vstd | (1 << nxt)));
    }
    return dpt[crr][vstd];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> cost[i][j];
        }
    }
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < (1 << 21); j++) {
            dpt[i][j] = -1;
        }
    }
    cout << dfs(0, 0) << "\n";
}