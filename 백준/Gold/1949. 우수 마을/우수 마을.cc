#include <iostream>
#include <vector>

using namespace std;

int N;
int dpt[10'001][2];
int population[10'001];
bool vstd[10'001];
vector<vector<int>> grp;

void dfs(int crr_node) {
    vstd[crr_node] = true;
    dpt[crr_node][0] = 0;
    dpt[crr_node][1] = population[crr_node];

    for (int nxt_node : grp[crr_node]) {
        if (vstd[nxt_node]) continue;
        dfs(nxt_node);
        dpt[crr_node][0] += max(dpt[nxt_node][0], dpt[nxt_node][1]);
        dpt[crr_node][1] += dpt[nxt_node][0];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> population[i];
    }
    grp.assign(N + 1, vector<int>());
    for (int i = 0; i < N - 1; i++) {
        int a, b;  cin >> a >> b;
        grp[a].push_back(b);
        grp[b].push_back(a);
    }
    dfs(1);
    cout << max(dpt[1][0], dpt[1][1]) << "\n";
}