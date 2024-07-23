#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> worker[1'001];
vector<int> occp;
vector<bool> vstd;

int N, M;

bool dfs(int bgn) {
    if (vstd[bgn]) return false;
    vstd[bgn] = true;
    for (int nxt : worker[bgn]) {
        if (occp[nxt] == 0 || dfs(occp[nxt])) {
            occp[nxt] = bgn;
            return true;
        }
    }
    return false;
}

int solution() {
    int res = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 2; j++) {
            vstd.assign(N + 1, false);
            if (dfs(i)) res++;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    occp.assign(M + 1, 0);
    for (int i = 1; i <= N; i++) {
        int wcnt;  cin >> wcnt;
        for (int j = 0; j < wcnt; j++) {
            int wn;  cin >> wn;
            worker[i].push_back(wn);
        }
    }
    cout << solution() << "\n";
}