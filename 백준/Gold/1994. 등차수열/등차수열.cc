#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<vector<int>> dpt;
vector<int> raw_vt;
vector<int> vt;

int N, res;

int get_idx(int nxt_num, int bgn) {
    int low = bgn, high = N - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (vt[mid] < nxt_num) {
            low = mid + 1;
        } else if (vt[mid] == nxt_num) {
            return mid;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int dp(int i, int j) {
    if (i > j) return 0;
    else if (i == j) return 1;
    if (dpt[i][j] != 0) return dpt[i][j];
    int nxt_num = 2 * vt[j] - vt[i];
    int nxt_idx = get_idx(nxt_num, j + 1);
    if (nxt_idx == -1) {
        dpt[i][j] = 2;
    } else {
        dpt[i][j] = dp(j, nxt_idx) + 1;
    }
    return dpt[i][j];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    dpt.assign(N + 1, vector<int>(N + 1, 0));
    for (int i = 0; i < N; i++) {
        int x;  cin >> x;
        raw_vt.push_back(x);
    }
    sort(raw_vt.begin(), raw_vt.end());
    int cnt = 1;
    vt.push_back(raw_vt[0]);
    for (int i = 1; i < N; i++) {
        if (raw_vt[i] == raw_vt[i - 1]) {
            cnt++;
        } else {
            res = max(res, cnt);
            cnt = 1;
            vt.push_back(raw_vt[i]);
        }
    }
    res = max(res, cnt);
    for (int i = 0; i < vt.size(); i++) {
        for (int j = i + 1; j < vt.size(); j++) {
            res = max(res, dp(i, j));
        }
    }
    cout << res << "\n";
}