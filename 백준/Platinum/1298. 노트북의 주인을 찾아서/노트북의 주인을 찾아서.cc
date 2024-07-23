#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<bool> vstd;
vector<int> occp;
vector<int> grp[110];

bool dfs(int strt) {
    for (int i = 0; i < grp[strt].size(); i++) {
        int goal = grp[strt][i];
        if (vstd[goal]) continue;
        vstd[goal] = true;
        if (occp[goal] == 0 || dfs(occp[goal])) {
            occp[goal] = strt;
            return true;
        }
    }
    return false;
}

int solution() {
    int res = 0;
    for (int i = 1; i <= N; i++) {
        vstd.assign(N + 1, false);
        if (dfs(i)) res++;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    occp.assign(N + 1, 0);
    while (M--) {
        int a, b;  cin >> a >> b;
        grp[a].push_back(b);
    }
    cout << solution() << "\n";
}