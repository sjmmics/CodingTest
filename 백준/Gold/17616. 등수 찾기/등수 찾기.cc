#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, K;
vector<vector<int>> grp, rgrp;
vector<bool> vstd;

pair<int, int> solution() {
    queue<int> que;
    que.push(K);
    int bgst = N;
    vstd[K] = true;
    while (!que.empty()) {
        int crr = que.front();
        que.pop();
        for (int nxt : grp[crr]) {
            if (vstd[nxt]) continue;
            vstd[nxt] = true;
            bgst--;
            que.push(nxt);
        }
    }
    int smst = 1;
    que.push(K);
    while (!que.empty()) {
        int crr = que.front();
        que.pop();
        for (int nxt : rgrp[crr]) {
            if (vstd[nxt]) continue;
            vstd[nxt] = true;
            smst++;
            que.push(nxt);
        }
    }
    return { smst, bgst };
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    
    grp.assign(N + 1, vector<int>());
    rgrp.assign(N + 1, vector<int>());
    vstd.assign(N + 1, false);
    for (int i = 0; i < M; i++) {
        int a, b;  cin >> a >> b;
        grp[a].push_back(b);
        rgrp[b].push_back(a);
    }
    pair<int, int> res = solution();
    cout << res.first << " ";
    cout << res.second << "\n";
}