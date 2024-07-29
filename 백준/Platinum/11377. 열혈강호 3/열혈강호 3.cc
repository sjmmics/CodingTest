#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
int occp[1'001];
vector<bool> vstd;
vector<int> grp[1'001];

bool dfs(int crr) {
    if (vstd[crr]) return false;
    vstd[crr] = true;
    for (int nxt : grp[crr]) {
        if (occp[nxt] == 0 || dfs(occp[nxt])) {
            occp[nxt] = crr;
            return true;
        }
    }
    return false;
}

int solution() {
    int ret = 0;
    for (int i = 1; i <= N; i++) {
        vstd.assign(N + 1, false);
        if (dfs(i)) {
            ret++;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        vstd.assign(N + 1, false);
        if (cnt >= K) break;
        if (dfs(i)) {
            ret++;
            cnt++;
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        int a;  cin >> a;
        for (int j = 0; j < a; j++) {
            int x;  cin >> x;
            grp[i].push_back(x);
        }
    }  
    cout << solution() << "\n";

}