#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int N, M;
vector<int> v[1001];
bool vstd[1001];
int work[1001];

bool dfs(int bgn) {
    if (vstd[bgn]) {
        return false;
    }

    vstd[bgn] = true;

    for (auto w : v[bgn]) {
        if (!work[w] || dfs(work[w])) {
            work[w] = bgn;
            return true;
        }
    }
    return false;
}

int solve() {
    int ret = 0;

    for (int i = 1; i <= N; i++) {
        memset(vstd, 0, sizeof(vstd));
        if (dfs(i)) {
            ret++;
        }
    }
    return ret;
}

int main() {

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int w;
            cin >> w;
            v[i].push_back(w);
        }
    }
    cout << solve() << endl;
}