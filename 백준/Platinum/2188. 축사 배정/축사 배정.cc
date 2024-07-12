#include <iostream>
#include <vector>
#include <string.h>

#define MAX_NUM 201

using namespace std;

vector<int> grp[MAX_NUM];
int vstd[MAX_NUM];
int matched[MAX_NUM];
int N, M;

bool dfs(int node) {
    if (vstd[node]) {
        return false;
    }
    vstd[node] = true;
    for (int nxt : grp[node]) {
        if (!matched[nxt] || dfs(matched[nxt])) {
            matched[nxt] = node;
            return true;
        }
    }
    return false;
}

int solve() {
    int res = 0;

    for (int i = 1; i <= N; i++) {
        memset(vstd, 0, sizeof(vstd));
        if (dfs(i)) {
            res++;
        }
    }
    
    return res;
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int S; 
        cin >> S;
        for (int j = 0; j < S; j++) {
            int x;
            cin >> x;
            grp[i].push_back(x);
        }
    }

    cout << solve();
}
